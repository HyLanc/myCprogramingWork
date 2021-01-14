#include<stdio.h>
#include<stdlib.h>
#include"myStrLib.h"
#include"mystrShape.h"
#include"mystrCypher.h"
#define sizelimit 100
char storage1[100];
char storage2[100];
int main(void){
    char storage[100],cypherstr[100];
    char ch,ch1,ch2;
    int width,history[100];
    printf("a: input two strings\n");
    printf("b: print strings in shapes\n");
    printf("c: use the cypher\n");
    printf("q: quit the program\n");
    ch= getchar();
    clear_input_queue();
    while (ch!='q'){
        switch (ch)
        {
        case 'a':
            printf("please enter two string then choose the string function you need\n");
            printf("enter the first strting\n");
            scanf("%s",&storage1);
            clear_input_queue();
            printf("now enter the second string\n");
            scanf("%s",&storage2);
            clear_input_queue();
            printf("l: use strlen\n");
            printf("c: use strcpy\n");
            printf("p: use strcmp\n");
            printf("q: quit this function\n");
            ch1=getchar();
            clear_input_queue();
            while (ch1!='q')
            {   
                switch (ch1)
                {
                case 'l':
                    printf("first string lenth %d\n",my_strlen(storage1));
                    printf("second string lenth %d\n",my_strlen(storage2));
                    break;
                case 'c':
                    printf("copy string2 to string 1\n");
                    my_strcpy(storage1,storage2);
                    printf("%s\n%s\n",storage1,storage2);
                    break;
                case 'p':
                    printf("compare two string which is bigger\n");
                    printf("%d\n",my_strcmp(storage1,storage2));
                    printf("answer 1 means string 1>string 2\n");
                    printf("answer 0 means string 1 equal to string 2\n");
                    printf("answer -1 means string 1<string 2\n");
                    break;
                default:
                    break;
                }
                printf("l: use strlen\n");
                printf("c: use strcpy\n");
                printf("p: use strcmp\n");
                printf("q: quit this function\n");
                ch1=getchar();
                clear_input_queue();
            }
            
            break;
        case 'b':
            printf("please enter a long string!\n");
            input_long_str(storage,sizelimit,'#');
            printf("please enter a width for the shape rectangle\n");
            scanf("%d",&width);
            print_str_in_rectangle(storage,width);
            break;
        case 'c':
            printf("please enter a string to cypher\n");
            scanf("%s",&cypherstr);
            mycypher(cypherstr,my_strlen(cypherstr),history);
            printf("%s\n",cypherstr);
        case 'q':
        default:
            break;
        }
        if(ch=='q')break;
        printf("a: input two strings\n");
        printf("b: print strings in shapes\n");
        printf("c: use the cypher\n");
        printf("q: quit the program\n");
        ch= getchar();
        clear_input_queue();
    }
}