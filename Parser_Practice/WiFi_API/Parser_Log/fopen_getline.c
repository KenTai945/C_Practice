#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	char buffer_ssid [128] = {0};
	char buffer_pwd  [64] = {0};

    fp = fopen("ssid_pwd.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
	}
	fscanf(fp,"%[^\n]", buffer_ssid);
	fscanf(fp,"%[^\n]", buffer_pwd);
    printf("Data from the file:\n%s\n", buffer_ssid);
	printf("Data from the file:\n%s\n", buffer_pwd);
    fclose(fp);


    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
