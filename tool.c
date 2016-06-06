#include<stdio.h>
#include<string.h>
char results[25];
char logs[25];
int pm=1;
int main(int argc,char *argv[])
{
	FILE *fp,*re;
	char buff[1024];
	strcpy(logs,"./logs/");
	strcpy(results,"./results/");
	strcat(results,argv[1]);
	strcat(logs,argv[1]);
	fp = fopen(logs,"r");
	re = fopen(results,"a");
	memset(buff,'0',sizeof(buff));
	//printf("argv[1]=%s\n",argv[1]);
	if(fp == NULL && re == NULL )
	{
		printf("Error in openinf file");
		return 0;
	}
//		printf("%s %s\n",results,logs);
	else{

	while(fgets(buff,sizeof(buff),fp) != 0){
	if(strstr(buff,"check_start"))
	{	
		while(strstr(buff,"check_stop") == 0)
		{
			fputs(buff,re);	
			fgets(buff,sizeof(buff),fp);
		}
			fputs(buff,re);	
	}//if
	}//while 
}//else
	memset(buff,'0',sizeof(buff));
	fclose(fp);
	fclose(re);
	return 0;
}
