#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main (int argc, char **argv) {

FILE *p1, *p2;

unsigned char str[255], carac;
int i,linha;

if(argc<2) {
    printf("sintax: %s file\n",argv[0]);
    exit(-99);
    }

strcpy(str,argv[1]);

if((p1=fopen(str,"r"))==NULL) {
    printf("File %s can not read\n");
    exit(-2);
    }
linha=i=0;
while(1) {
    carac=fgetc(p1);
    if(carac==EOF)
        break;
    str[i]=carac;
    if(++i>12) {
        for(i=0;i<13;i++)
            printf("%3x ",str[i] & 0xff);
        printf("  |  ",str[i]);
        for(i=0;i<13;i++)
            printf("%3o ",str[i]);
        printf("  |  ",str[i]);
        for(i=0;i<13;i++) {
            if(str[i]!='\n')
                printf("%c ",str[i]);
            else
                printf("%c ",' ');
            }
        i=0;
        printf(" |\r\n");
        if(++linha>20) {
            linha=0;
            getchar();
            }
        }

}

fclose(p1);
fclose(p2);

}
