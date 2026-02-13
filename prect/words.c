#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100

void main(){


    char str1[max];

    char str2[50];

    printf("enter a string\n");
    fgets(str1, sizeof(str1), stdin);

    printf("this is what u entered %s\n", str1);

    printf("enter the substring to be searched\n");
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] == '\0';

    str2[strcspn(str2, "\n")] == '\0';

    char *pos;
    pos = str1;
    int count = 0;

    while(pos = strstr(pos, str2)!=NULL){
        count++;
        pos++;
    }

    printf("the substring occurs %d times\n",count);
}
