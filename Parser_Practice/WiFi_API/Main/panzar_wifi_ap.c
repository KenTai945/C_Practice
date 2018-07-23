#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ON	"1"
#define OFF	"0"
#define DELAY 0.3

#define WIFI_IF "wlx4c0fc716fbaf"
#define WIFI(st) system("echo "st" > /sys/class/edm/gpio/USB_OTG2/value")
//#define WIFI_G_CONFIG "/etc/g_mode_config.conf"
//#define WIFI_N_CONFIG "/etc/g_mode_config.conf"

/* excute the shell script */


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
		printf("Usage: %s [-g/-n/-k]\n", argv[0]);
		return -1;
	}

	while((opt = getopt(argc, argv, "gnk")) != -1){
		switch(opt){
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
		default:
			printf("Unknow argument\n");
		}
	}

	return 0;
}

