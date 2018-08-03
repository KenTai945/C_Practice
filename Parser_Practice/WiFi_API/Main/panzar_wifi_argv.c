#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ON	"1"
#define OFF	"0"
#define DELAY 0.5

#define WIFI_IF "wlx4c0fc716fbaf"
#define WIFI(st) system("echo "st" > /sys/class/edm/gpio/USB_OTG2/value")

#define station_txt "/etc/wificonfig/station_ssid_pwd.txt"
#define ap_n_txt "/etc/wificonfig/n_ssid_pwd.txt" 
#define ap_g_txt  "/etc/wificonfig/g_ssid_pwd.txt"
#define parser_log "/var/log/kern.log" 

/*
 	Copyright (c) 2018, Polin Chen <mayqueen@gmail.com> and MayQueen contributors
	This software may be distributed under the terms of the BSD license.
*/


/*
 	Target: turn off the station mode and set to 0

	(a)the station mode would excute two process: 
		(1) wpa_supplicant
		(2) dhclient
 	
	(b)Besides, turn off the hardware sent 0 to gpio USB_OTG2 to turn off the wifi mode
	(c)Be carefu the DELAY time
*/


static void kill_station(void)
{
	/*kill the process wpa_supplicant*/  //system("pkill wpa_supplicant > /home/mayqueen/wifi_off_record.txt 2>&1");
	system("pkill wpa_supplicant > /dev/null 2>&1");
	/*kill the process dhclient*/ //system("pkill dhclient > /home/mayqueen/wifi_off_record.txt 2>&1");
	system("pkill dhclient > /dev/null 2>&1");
	sleep (DELAY);
	/* Turn off the hardware Wi-Fi*/
	WIFI(OFF);
	/* Delay 0.5 sec*/
	sleep(DELAY);
}

/*
	Target: store the stdin in the buffer and sent to the different conf file(mode.txt)

	(a)"fget" to store the stdin
	(b)store the stdin to the buffer, 
		(1) be careful about the "\n",and deleted the keyin "enter"
	(c)fwrite to the conf
*/

static void setup_ssid_pwd(int variable)
{
	FILE *fp;
	char buffer_ssid [32] = {0};
	char buffer_pwd [16] = {0};
	/*
	   get the ssid account
	*/
	printf("enter the Account\n");
	fgets(buffer_ssid, sizeof(buffer_ssid), stdin);
	buffer_ssid[strlen(buffer_ssid) - 1] = '\n';//deletd the keyin "enter"
	size_t ssid_length = strlen(buffer_ssid);
	/*
	   get the pwd password
	*/
	printf("enter thr passwpord\n");
	fgets(buffer_pwd, sizeof(buffer_pwd), stdin);
	if(strlen(buffer_pwd) < 8){
		printf("*** the length of password is not long enough ***\n");
	}
	buffer_pwd[strlen(buffer_pwd) - 1] = '\n';// the stdin would create 
	size_t pwd_length = strlen(buffer_pwd);

	switch (variable)   {
		case 1:
			/*write to the station.txt*/
			fp = fopen(station_txt, "w+");
			fwrite(buffer_ssid , 1, ssid_length, fp);
			fwrite(buffer_pwd, 1, pwd_length, fp);
			fclose(fp);
			break;
		case 2:
			/*write to the n_mode.txt*/	
			fp = fopen(ap_n_txt, "w+");
			fwrite(buffer_ssid , 1, ssid_length, fp);
			fwrite(buffer_pwd, 1, pwd_length, fp);
			fclose(fp);
			break;
		case 3:
			/*write to the g_mode.txt*/
			fp = fopen(ap_g_txt, "w+");
			fwrite(buffer_ssid , 1, ssid_length, fp);
			fwrite(buffer_pwd, 1, pwd_length, fp);
			fclose(fp);
			break;
		default:
			printf("The option is not available\n");
			break;
	}
}

/*

Target: store the account and password to the buffer

(a) *fp to open the conf file(.txt) to read the account and password

(b) memcpy to the buffer and check the length

(c) *ssid ,*pwd to store the buffer in to the account and password
*/

static int fillin_ssid_pwd(char *ssid,char *pwd,int a)
{
	FILE *fp;
	char buf[128] = {0};
	size_t rlen;
	//read the station's ssid & pwd 
	if ( a == 1){
		fp = fopen(station_txt, "r");
		if(!fp){
			printf("fopen ssid_pwd.txt failed\n");
			return -1;
		}
	}
	// read the ap n mode's ssid & pwd
	else if ( a == 2){
		fp = fopen(ap_n_txt, "r");
		if(!fp){
			printf("fopen ssid_pwd.txt failed\n");
			return -1;
		}
	}
	// read the ap g's ssid & pwd
	else {
		fp = fopen(ap_g_txt, "r");
		if(!fp){
			printf("fopen ssid_pwd.txt failed\n");
			return -1;
		}
	}
	//TODO: error check
	rlen = fread(buf, 1, sizeof(buf), fp);
	buf[rlen] = '\0';

	int pos = 0;

	for(pos = 0; pos < rlen; pos++){
		if (buf[pos] == '\n')
			break;
	}

	memcpy(ssid, buf, pos+1);
	ssid[pos+2] = '\0';
	char *string_ptr;
	int count = 0;
	for(string_ptr = (buf+pos-2); *string_ptr != '\0'; string_ptr++){
		count ++;
	}
	memcpy(pwd, &buf[pos+1],sizeof(pwd)/sizeof(pwd[0]) - count);
	return 0;
}

/*
Target: Generated the wifi.conf

(a) store the ssid and pwd
(b) use the snprintf to generate the cmd with ssid and password 
(c) generate the cmd: "wpa_passpharse" + ssid &pwd to generate the wifi.conf 
*/

static void station_ssid_pwd(void)
{
	char cmd[256] = {0};
	char ssid[64] = {0};
	char pwd[64] = {0};

	fillin_ssid_pwd(ssid, pwd, 1);
	ssid[strlen(ssid) - 1] = '\0';//don't fotget to make the array last element clean
	pwd[strlen(pwd) - 1] = '\0';//don't forget to make the arary last element clean
	//printf("%s(%d): ssid: %s, pwd: %s\n", __func__, __LINE__, ssid, pwd);
	snprintf(cmd, sizeof(cmd), 
			"wpa_passphrase %s %s > /etc/wificonfig/wifi_home.conf",
			ssid, pwd);
	system(cmd);
}



static void help(void)
{
	printf("Panzar Wi-Fi Feature v1.0\n");
	printf("\tCopyright (c) 2018, Polin Chen <mayqueen@gmail.com> and contributors\n");
	printf("This software may be distributed under the terms of the BSD license.\n");
	printf("See README for more details.\n");
	printf("\nusage:\n");
	printf("\tpanzar_wifi [-s] [-sta]/[-ap_n]/[-ap_g]\
			[-c] [-sta]/[-ap_n]/[-ap_g]\
			[-k] \n");
	printf("\ndrivers:\n");
	printf("\trtl871xdrv,rtl8188eu\n");
	printf("\noptions:\n");
	printf("\t-s -sta = set up station mode of id and password\n");
	printf("\t-s -ap_n = set up 80211 n mode of id and password\n");
	printf("\t-s -ap_g = set up 80211 g mode of id and password\n");
	printf("\t-c  -sta = connect to the station  mode\n");
	printf("\t-c  -ap_n = excute the 80211 n of AP mode\n");
	printf("\t-c  -ap_g = excue the 80211 g  of AP mode\n");
	printf("\t-k = kill all the  wifi prcoess\n");
	printf("\nexample:\n");
	printf("\tpanzar_wifi -s\n");
	printf("\tpanzar_wifi -g\n");
	printf("\tpanzar_wifi -a\n");
}
/*
	Target:excute the station connection
*/
static void station(void)
{
	WIFI(ON);
	sleep(DELAY);

	system("rm /etc/wificonfig/wifi_home.conf");
	station_ssid_pwd();
	sleep(DELAY*4);//be careful about the timing issue
	system("ifconfig wlx4c0fc716fbaf up");
	sleep(DELAY);

	system("wpa_supplicant -i wlx4c0fc716fbaf -c /etc/wificonfig/wifi_home.conf -Dwext & > /home/mayqueen/on_record.txt 2>&1");
	system("./parser_strstr");
	//printf("wpa_supplicant -i wlx4c0fc716baf -c done\n");

	sleep(DELAY);
	system("dhclient wlx4c0fc716fbaf > /home/mayqueen/on_record.txt 2>&1");
	//printf("dhclinet wlx4c716fbaf done/n");
}

/*
 *  Target: excute the create_ap_g mode
 */
static void create_ap_g(void)
{
	/*
	 *
	 * get ssid & pwd and store it in to the buffer
	 *
	 */
	char cmd[256] = {0};
	char ssid[64] = {0};
	char pwd[64] = {0};

	fillin_ssid_pwd(ssid, pwd, 3);
	ssid[strlen(ssid) - 1] = '\0';//don't fotget to make the array last element clean
	pwd[strlen(pwd) - 1] = '\0';//don't forget to make the arary last element clean
	//printf("%s(%d): ssid: %s, pwd: %s\n", __func__, __LINE__, ssid, pwd);
	snprintf(cmd, sizeof(cmd),"create_ap --driver rtl871xdrv --daemon \
			wlx4c0fc716fbaf eth0 %s %s", ssid, pwd);

	/* reset wifi chip */
	WIFI(OFF);
	sleep(DELAY);
	WIFI(ON);
	sleep(DELAY);
	/* Send stop command to an already running create_ap */
	system("create_ap --stop" WIFI_IF);
	/* excute the createap to set the board as the AP mode with 80211n */
	system(cmd);
}
/*
 *  Target: excute the create_ap_n mode
 */
static void create_ap_n(void)
{

	/*
	 *
	 * get ssid & pwd and store it in to the buffer
	 *
	 */
	char cmd[128] = {0};
	char ssid[32] = {0};
	char pwd[32] = {0};

	fillin_ssid_pwd(ssid, pwd, 2);
	ssid[strlen(ssid) - 1] = '\0';//don't fotget to make the array last element clean
	pwd[strlen(pwd) - 1] = '\0';//don't forget to make the arary last element clean
	//printf("%s(%d): ssid: %s, pwd: %s\n", __func__, __LINE__, ssid, pwd);
	snprintf(cmd, sizeof(cmd),"create_ap --driver rtl871xdrv --ieee80211n --daemon \
			wlx4c0fc716fbaf eth0 %s %s", ssid, pwd);
	/* reset wifi chip*/
	WIFI(OFF);
	sleep(DELAY);
	WIFI(ON);
	sleep(DELAY);
	/*Send stop command to an already running create_ap.    */
	system("create_ap --stop" WIFI_IF);
	/*excute the createap to set the board as the AP mode with 80211n       */
	system(cmd);
}

static void kill_ap(void)
{
	/* Send stop command to an already running create_ap. */
	system("pkill create_api");
	WIFI(OFF);
	printf("end of the kill_ap excution\n");
}

int main(int argc, char **argv)
{
	if(argc < 2){
		printf("Usage: %s [-s/-c/-k/-h]\n", argv[0]);
		return -1;
	}
	if (strcmp(*(argv+1), "-s") == 0){
		printf("excute the ssid password set up\n");
		if (strcmp(*(argv+2), "-sta") == 0){
			printf("station ssid & pwd set up\n");
			setup_ssid_pwd(1);
		}
		else if (strcmp(*(argv+2), "-ap_n") == 0){
			printf("ap n mode ssid & pwd set up\n");
			setup_ssid_pwd(2);
		}
		else if (strcmp(*(argv+2), "-ap_g") == 0){
			printf("ap g mode ssid & pwd set up\n");
			setup_ssid_pwd(3);
		}
		else {
			printf("the second option is not available\n");
		}			 
	}
	else if(strcmp(*(argv+1), "-c") == 0){
		printf("excute the connection\n");
		if (strcmp(*(argv+2), "-sta") == 0){
			printf("excute the station connection \n");
			printf("excution the station mode\n");
			kill_station();
			kill_ap();
			station();
		}
		else if (strcmp(*(argv+2), "-ap_n") == 0){
			printf("excution the n mode connection\n");
			printf("Excute the Wi-Fi AP 802.11n mode\n");
			kill_station();
			kill_ap();	
			create_ap_n();	
		}
		else if (strcmp(*(argv+2), "-ap_g") == 0){
			printf("excute the g mode connecton\n");
			printf("Excute the Wi-Fi AP 802.11g mode\n");
			kill_station();
			kill_ap();
			create_ap_g();
		}
		else {
			printf("the second option is not available\n");
		}			 

	}
	else if(strcmp(*(argv+1), "-k") == 0){
		kill_station();
		kill_ap();
		printf("kill the connection\n");
	}
	else if(strcmp(*(argv+1), "-h") == 0){
		help();
	}
	return 0;
}
