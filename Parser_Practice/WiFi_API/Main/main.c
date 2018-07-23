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

	snprintf(cmd, sizeof(cmd),"wpa_passphrase %s %s > ./wifi_home.conf", buffer_ssid, buffer_pwd);
	printf("%s\n", cmd);//systtem(cmd);
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
	printf("excute the help option\n");
	exit(0);
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
    system("create_ap --stop wlx4c0fc716fbaf");

	WIFI(OFF);
}

int main(int argc, char **argv)
{
	int opt;

	if(argc < 2){
		printf("Usage: %s [-s/-g/-n/-k/-h]\n", argv[0]);
		return -1;
	}

	while((opt = getopt(argc, argv, "sgnkh")) != -1){
		switch(opt){
		case 's':
			printf("set up the ID and passqord\n");
			ssid_pwd();
			break;
		case 'g':
			printf("Excute the Wi-Fi AP 802.11g mode\n");
			create_ap_g();                                                                             
			break;
		case 'n':
			printf("Excute the Wi-Fi AP 802.11n mode\n");	
			create_ap_n();                                                                              
			break;
		case 'k':
			printf("turn off the Wi-Fi AP mode\n");   
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

