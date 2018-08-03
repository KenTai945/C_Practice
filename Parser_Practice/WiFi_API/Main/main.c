#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ON	"1"
#define OFF	"0"
#define DELAY 0.3

#define WIFI_IF "wlx4c0fc716fbaf"
#define WIFI(st) system("echo "st" > /sys/class/edm/gpio/USB_OTG2/value")
//#define WIFI_G_CONFIG "/etc/g_mode_config.conf"
//#define WIFI_N_CONFIG "/etc/g_mode_config.conf"

/* excute the shell script */

static void ssid_pwd(void)
{
	char buffer_ssid [32] = {0};
	char buffer_pwd [16] = {0};
	char cmd[128];
	/*
		get the ssid account
	*/
	printf("enter the Account\n");
	fgets(buffer_ssid, sizeof(buffer_ssid), stdin);
	buffer_ssid[strlen(buffer_ssid) - 1] = '\0';//deletd the keyin "enter" 
	/*
		get the password
	*/
	printf("enter thr passwpord\n");
	fgets(buffer_pwd, sizeof(buffer_pwd), stdin);
	buffer_pwd[strlen(buffer_pwd) - 1] = '\0';

	snprintf(cmd, sizeof(cmd),"wpa_passphrase %s %s > wifi_home.conf", buffer_ssid, buffer_pwd);
	printf("%s\n", cmd);
	system(cmd);
}

static void kill_station(void)
{
	/*kill the process wpa_supplicant*/
    system("pkill wpa_supplicant > /home/mayqueen/wifi_off_record.txt 2>&1");
    /*kill the process dhclient*/
    system("pkill dhclient > /home/mayqueen/wifi_off_record.txt 2>&1");
	sleep (DELAY);
    /* Turn off the hardware Wi-Fi*/
    WIFI(OFF);
    /* Delay 0.5 sec*/
    sleep (DELAY);
}


static void help(void)
{
	printf("Panzar Wi-Fi Feature v1.0\n");
	printf("\tCopyright (c) 2018, Polin Chen <mayqueen@gmail.com> and contributors\n");
	printf("This software may be distributed under the terms of the BSD license.\n");
	printf("See README for more details.\n");
	printf("\nusage:\n");
    printf("\tpanzar_wifi [-BddhKLqqstuvW] [-P<pid file>] [-g<global ctrl>] \
        [-G<group>] \
        -i<ifname> -c<config file> [-C<ctrl>] [-D<driver>] [-p<driver_param>] \
        [-b<br_ifname>] [-e<entropy file>] [-f<debug file>] \
        [-o<override driver>] [-O<override ctrl>] \
        [-N -i<ifname> -c<conf> [-C<ctrl>] [-D<driver>] \
        [-m<P2P Device config file>] \
        [-p<driver_param>] [-b<br_ifname>] [-I<config file>] ...]\n");

	printf("\ndrivers:\n");
	printf("\trtl871xdrv,rtl8188eu\n");
	printf("\noptions:\n");
	printf("\t-s = set up id and password\n");
	printf("\t-g = 80211 g mode\n");
    printf("\t-n = 80211 n mode\n");
    printf("\t-a = ap mode wifi\n");
	printf("\nexample:\n");
	printf("\tpanzar_wifi -s\n");
	printf("\tpanzar_wifi -g\n");
	printf("\tpanzar_wifi -a\n");
}
static void station(void)
{
	/*
		wpa_supplicant -i wlan0 -c wifi_home.conf &
		dhclient wlan0
	*/
	WIFI(ON);
	sleep(DELAY);
	system("ifconfig wlx4c0fc716fbaf up");
	system("wpa_supplicant -i wlx4c0fc716fbaf -c wifi_home.conf -Dwext & > /home/mayqueen/on_record.txt 2>&1");
	system("dhclient wlx4c0fc716fbaf > /home/mayqueen/on_record.txt 2>&1");
	/*
	check the interface again
	*/	
	//cat ifconfig to do the parser
	exit (0);
}

static void create_ap_g(void)
{
	/* reset wifi chip */
	WIFI(OFF);
	sleep(DELAY);
	WIFI(ON);
	sleep(DELAY);
	/* Send stop command to an already running create_ap */
	system("create_ap --stop" WIFI_IF);
	/* excute the createap to set the board as the AP mode with 80211n */
	system("create_ap --daemon --config /etc/g_mode_config.conf");
}

static void create_ap_n(void)
{
	/* reset wifi chip*/
	WIFI(OFF);
	sleep(DELAY);
	WIFI(ON);
	sleep(DELAY);
	/*Send stop command to an already running create_ap.    */
	system("create_ap --stop"WIFI_IF);
	/*excute the createap to set the board as the AP mode with 80211n       */
	system("create_ap --daemon --config /etc/n_mode_config.conf");
}

static void kill_ap(void)
{
	/* Send stop command to an already running create_ap. */
    system("pkill create_ap > /dev/null");
	WIFI(OFF);
}

int main(int argc, char **argv)
{
	int opt;

	if(argc < 2){
		printf("Usage: %s [-s/-g/-n/-k/-h]\n", argv[0]);
		return -1;
	}

	while((opt = getopt(argc, argv, "sagnkh")) != -1){
		switch(opt){
		case 's':
			printf("set up the ID and passqord\n");
			ssid_pwd();
			break;
		case 'a':
			printf("excution the station mode\n");
			kill_station();
			kill_ap();
			station();
			break;
		case 'g':
			printf("Excute the Wi-Fi AP 802.11g mode\n");
			kill_station();
			kill_ap();
			create_ap_g();                                                                             
			break;
		case 'n':
			printf("Excute the Wi-Fi AP 802.11n mode\n");
			kill_station();
			kill_ap();	
			create_ap_n();                                                                              
			break;
		case 'k':
			printf("turn off the Wi-Fi AP mode\n");   
			kill_station();	
			kill_ap();                                                                              
			break;
		case 'h':
			help();
			break;
		default:
			printf("Unknow argument\n");
		}
	}
	return 0;
}

