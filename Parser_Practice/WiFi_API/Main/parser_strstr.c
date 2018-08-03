#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


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
	Target: Using the strstr to check for the log message have the "wifi setup" for 5 times 
	
	Step By step:
	(1)set up the fp to point to the log file 
	(2)read the lat part of the log ot store in the buffer
	(3)compare the string to return the ptr, to check the parser
*/
//ERROR sta recv deauth reason code

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

static int parser_pwd(void)
{
	char buffer_pwd[64] = {0};
	FILE *fp_pwd;
	fp_pwd = fopen("/var/log/kern.log","r+");
	if(fp_pwd == NULL){
		perror("Error opening file");
		return(-1);
	}	
	fseek(fp_pwd,0L,SEEK_END);	// seek to end of file
	fseek( fp_pwd, -64, SEEK_END );
	
	fread(buffer_pwd,64,1,fp_pwd);
	//puts(buffer_pwd);
	rewind(fp_pwd);

	char *pwd_check;
	
	pwd_check = strstr(buffer_pwd,"link becomes ready");//link becomes ready //sta recv deauth reason code"

	if (pwd_check != NULL){
		//printf("\n");
		//printf("password correct\n");
		return 0;
	}
	else	{
		return 1;
	}
	fclose(fp_pwd);// important, don't gorget
}

static int parser_check()
{
	char buffer[256] = {0};
	FILE *fp;
	fp = fopen("/var/log/kern.log","r+");
	if(fp == NULL){
		perror("Error opening file");
		return(-1);
	}	
	fseek(fp,0L,SEEK_END);	// seek to end of file
	fseek( fp, -256, SEEK_END );
	
	//fread(buffer,sz_of_txt/4,1,fp);
	fread(buffer,256,1,fp);
	//puts(ptr);
	rewind(fp);

	char *parsercheck;

	/*
	 *
	 *	check the password is correct or not
	 *
	 */

	parsercheck = strstr(buffer,"wlx4c0fc716fbaf: link becomes ready");
	if (parsercheck != NULL){
		int pwd_count = 0;
		int pwd_check;
		int pwd_check_two;
		while(pwd_count < 12)
		{
			sleep(0.5);
			pwd_check = parser_pwd();
			if(pwd_check == 0){
				sleep(7);
				pwd_check_two = parser_pwd();
				if(pwd_check_two == 0)
				{
					printf("*** connection sucessful ***\n");
					break;
				}
			}
			else	{
				pwd_count ++;
			}
			sleep(DELAY*2);
		}
		if (pwd_count >= 12)
		{
			printf("*** password may be not correct ***\n");
			kill_station();
		}
		return 0;		
	}
	else{
		//printf("not found\n");
		return 1;
	}
	fclose(fp);// important, don't gorget
}

int main(void)
{
	int find = 0;
	int count = 0;
	while(count < 10)
	{
		find = parser_check();
		if(find == 0){
			break;
		}
		else {
			count++;
		}
		sleep(3);
	}
	if (count >= 8){

		printf("*** the wifi link connection is failed, check the account ***\n");
		kill_station();
	}
	return 0;
}	
