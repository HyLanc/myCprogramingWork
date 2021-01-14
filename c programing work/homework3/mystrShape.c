#include<stdio.h>
#include"mystrShape.h"
void clear_input_queue(void){
    while (getchar()!='\n')
    {
        continue;
    }
}
int input_long_str(char storage[], unsigned int sizeLimit, int endMark){
    char str[100];
    int i=0;
    char ch;
    while ((ch=getchar())!=endMark)
    {
        str[i++]=ch;
        putchar(ch);
        printf("\n");
    }
    str[i]='\0';
    int j;
    for(j=0;j<=sizeLimit;j++)
    {
        storage[j]=str[j];
    }
    return 0;
}
void print_str_at_center(const char str[]){
     int j,i=0;
     int count;
     int row[10]={0};
     while(str[i]!='\0'){
         if(str[i]!='\n'){
             count ++;
         }
         else
         {
             row[j]=count;
             j++;
             count=0;
         }
         i++;
     }
     int compare=1;
     for(int k=0;k<=10;k++){
         if(row[compare]<row[k]){
             compare=k;
         }
         else
         {
             continue;
         }
         
     }
    
}
void print_str_in_rectangle(const char str[], unsigned int row_width){
    int i=0;
    while (str[i]!='\0')
    {   
        if(str[i]=='\n'){
            i++;
            continue;
        }
        putchar(str[i]);
        if(i%row_width==0){
            printf("\n");
        }
        i++;
    }
    printf("\n");
}