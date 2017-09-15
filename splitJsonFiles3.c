#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}

int main(int argc, char **argv) {

FILE *p1, *p2;

char carac, str[255], str2[255];
int i=1, start=0;

if(argc<2) {
	printf("Sintax: %s file_in ",argv[0]);
	exit (-1);
	}
strcpy(str,"data/");
strcat(str,argv[1]);
if((p1=fopen(str,"r"))==NULL) {
	printf("File %s not found",str);
	exit(-2);
	}
start=0;
while(carac=fgetc(p1)) {
	if(carac==EOF) {
		fcloseall();
		exit(1);
		}
	if((carac=='{') && (start==0)) {
		start=1;
		strcpy(str,"acervo3/");
		strcat(str,argv[1]);
		str[strlen(str)-4]='\0';
		strcat(str,itoa(i++,10));
		strcat(str,".txt");
		if((p2=fopen(str,"w"))==NULL) {
			printf("File %s can not create\n",str);
			exit(-3);
			}
		}
	if(carac=='\r') {
		start=0;
		fclose(p2);
		}
	if(start) 
		fputc(carac,p2);
	}
}
