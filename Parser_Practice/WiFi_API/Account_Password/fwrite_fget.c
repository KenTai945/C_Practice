#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
/*
	Target:
	(1) store the account and password through the buffer.
	(2) store data to the buffer in the stdin through the fget()
	(3) snprintf to use system call generate the conf file
	//system("wpa_passphrase icannottellyou_RPT 77777777 > ./wifi_home.conf");
*/




int main (void) {

	FILE *fp;
	char buffer_ssid [20] = {0}; //Be careful to store reset the value	
	char buffer_pwd[20]={0};
	//char *string_ptr_ssid = buffer_ssid; 
	//char *string_ptr_pwd = buffer_pwd;
	//char *tmp = buffer_ssid;
	
	fp = fopen( "file.txt" , "w" );
	printf("enter the Account\n");                                                                                                                                     
	fgets(buffer_ssid, sizeof(buffer_ssid), stdin);
	printf("enter the Password\n");
	fgets(buffer_pwd, sizeof(buffer_pwd), stdin);
	
	snprintf(cmd, sizeof(buffer_ssid), "cal %d %d", month, year);
	system(cmd);	
	/*	
		careate snprintf 
	*/

	system("wpa_passphrase %s %s > ./wifi_home.conf");


	/*
		(1)remove the space store int the string of buffer
		
		while (*string_ptr_ssid){
        	if (*string_ptr_ssid != ' '){
            *tmp++ = *string_ptr_ssid;
        	string_ptr_ssid++;
			}
    	}
		(2)remove the space store int the string of buffer
		
		*tmp = 0;	
		*tmp = buffer_pwd;
		while (*string_ptr_pwd){
        	if (*string_ptr_pwd != ' '){
            *tmp++ = *string_ptr_pwd;
        	string_ptr_pwd++;
			}
    	}	
	*/

	/*
		renove space
	*/

	//*tmp =0;
	fwrite(buffer_ssid, 1, sizeof(buffer_ssid) , fp);
	fwrite("/n", 1, sizeof(char) , fp);
	fwrite(buffer_pwd, 1, sizeof(buffer_pwd), fp);
	close(fp);
	return(0);
}
