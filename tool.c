#include<stdio.h>
#include<string.h>
char buff[100];
char results[25];
char logs[25];
int main(int argc,char *argv[])
{
	FILE *fp,*re;
	strcpy(logs,"./logs/");
	strcpy(results,"./results/");
	strcat(results,argv[1]);
	strcat(logs,argv[1]);
	fp = fopen(logs,"r");
	//printf("argv[1]=%s\n",argv[1]);
	if(fp == NULL)
	{
		printf("Error in openinf file");
		return 0;
	}
		printf("%s %s\n",results,logs);

	while(fgets(buff,sizeof(buff),fp) != 0){
	if(strstr(buff,"check_start"))
	{
		printf("Inside while\n");
		re = fopen(results,"a+");
		if(re == NULL)
		{
			printf("error in opening file re\n");
			return 0;
		}
		while(strstr(buff,"check_stop") == 0)
		{
			fputs(buff,re);	
			fgets(buff,sizeof(buff),fp);
		//	printf("%s",buff);
		}
			//fputs("\n---------------After suspend---------\n",re);
			fputs(buff,re);	
	}//if
	}//while 
	fclose(fp);
	fclose(re);
	return 0;
}
