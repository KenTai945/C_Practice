#include<stdio.h>
#include<stdlib.h>
/*
	Target: 
		(1)use scanf to store data for account and password
		(2)use printf to get the value 
		(3)use the fgets function to store password and 
		(4)utilize the fgtes 
		(5)compare the feature of the scanf and fgets
	Future Work
		(1)write to the test.txt as the conf for Wi-Fi API
		(2)make what we enter to disappear
	Problem
		(1)using GDB to debug
		(2)use system to write to the .txt insteading of the .conf 
*/
int main(void)
{
	char account_scanf[20];
	
	char password_scanf[20];

	char account_fgets[20];

	char password_fgets[20];
	
	printf("please enter the password and document:\n");
	
	scanf("%19s %19s",account_scanf,password_scanf);/* the maxium of Character is 19,bcz scan including the "\0"*/
	
	printf("Account is :%s Password is:%s\n",account_scanf,password_scanf);

	printf("fgets mode\n");
	
	printf("enter the Account\n");

	fgets(account_fgets,sizeof(account_fgets),stdin);

	printf("enter the Password\n");

	fgets(password_fgets,sizeof(password_fgets),stdin);	
	
	printf("Account is :%s Password is:%s\n",account_fgets,password_fgets);

	return 0;
}
