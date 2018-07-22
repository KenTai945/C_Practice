#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	Target:
	(1) store the account and password through the buffer.
	(2) store data to the buffer in the stdin through the fget()
	(3) snprintf to use system call generate the conf file
	//system("wpa_passphrase icannottellyou_RPT 77777777 > ./wifi_home.conf");
	
	Question:
	(1) when we enter the ssid to scanf the data would have the problem for "enter"
	(2) How to know the system(cmd) could work?
	
	Solution:
	(1)	assign 0 to the last array of ssid(pwd)
	(2)	using the printf to display the system
*/




int main (void)
{
	char buffer_ssid [16] = {0}; //Be careful to store reset the value to clean clearly or some unknow varible would in the array	
	char buffer_pwd[16]={0};
	char cmd[128];
	
	printf("enter the Account\n");                                                                                                                                     
	fgets(buffer_ssid, sizeof(buffer_ssid), stdin);
	buffer_ssid[strlen(buffer_ssid)-1] = 0;
	printf("enter the Password\n");                                                                                                                                    
    fgets(buffer_pwd, sizeof(buffer_pwd), stdin);
	buffer_pwd[strlen(buffer_pwd)-1] = 0;
	/*
		snprintf(char *str, size_t size, "%s",const char *format, ...)
		(argumets 1)*str : is a buffer.
		(arguments 2)size : is the maximum number of bytes (characters) that will be written to the buffer.
		(arguments 3) just the string formats like (arguments1 ,arguments2 ,“%d”, myint) 
		(arguments 4)format : C string that contains a format string that follows
    */   
	snprintf(cmd, sizeof(cmd),"wpa_passphrase %s %s > ./wifi_home.conf",buffer_ssid,buffer_pwd);
	printf("%s\n",cmd);//using the printf to display the system
	return 0;
}
