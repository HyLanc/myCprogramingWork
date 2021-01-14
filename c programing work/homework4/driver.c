#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include "list.h"
#include "ui.h"
#include "matrix.h"
int main(int argc,char * argv []){
    int row1,column1,column2;//矩阵乘法前一个矩阵的列等于后一个矩阵行才可行 故不设第二个矩阵的行
    int matrix1[MAX][MAX],matrix2[MAX][MAX],matrix3[MAX][MAX];
    FILE *FPIN;
    FILE *FPOUT;
    Node *Number1=NULL;
    Node *Operator=NULL;
    Node *Number2=NULL;
    show_menu();
    char ch1;
    ch1=getchar();
    clear_input_queue();
    while (1)
    {
        switch (ch1)
        {
        case 'a':
        {
            srand((unsigned)time(NULL));
            int num=rand();
            int number1=rand(),number2=rand();
            char operator;
            if((num%100+1)<=25)
            operator='+';
            else if(((num%100)+1)<=50&&((num%100)+1)>25)
            operator='-';
            else if (((num%100)+1)<=75&&((num%100)+1)>50)
            operator='*';
            else if (((num%100)+1)<=100&&((num%100)+1)>75)
            operator='/';
            Number1=append_data(Number1,number1);
            Operator=append_data(Operator,operator);
            Number2=append_data(Number2,number2);
            break;
        }

        case 'b':
        {
            Node *nd1=Number1,*nd2=Operator,*nd3=Number2;
            while (nd1!=NULL)
            {
                print_node(nd1);
                print_cnode(nd2);
                print_node(nd3);
                puts("");
                nd1=nd1->next;
                nd2=nd2->next;
                nd3=nd3->next;
            }
            break;
        }
            
        case 'c':
        {
            FPOUT=fopen(argv[1],"a");
            int number1, number2;
            char operator;
            printf("please enter an integer\n");
            scanf("%d",&number1);
            clear_input_queue();
            printf("please enter an operator\n");
            scanf("%c",&operator);
            clear_input_queue();
            printf("please enter an integer\n");
            scanf("%d",&number2);
            clear_input_queue();
            fprintf(FPOUT,"%d",number1);
            putc(operator,FPOUT);
            fprintf(FPOUT,"%d",number2);
            fprintf(FPOUT," ");
            fclose(FPOUT);
            break;

        }
        case 'd':
        {
            FPIN=fopen(argv[1],"r");
            int number1,number2;
            char operator; 
            rewind(FPIN);
            fscanf(FPIN,"%d",&number1);
            fscanf(FPIN,"%c",&operator);
            fscanf(FPIN,"%d",&number2);
            Number1=append_data(Number1,number1);
            Operator=append_data(Operator,operator);
            Number2=append_data(Number2,number2);
            fclose(FPIN);
            break;
        }
            
        case 'e':
        {
            int number1,number2;
            char operator;
            printf("please enter an integer\n");
            scanf("%d",&number1);
            clear_input_queue();
            printf("please enter an operator\n");
            scanf("%c",&operator);
            clear_input_queue();
            printf("please enter an integer\n");
            scanf("%d",&number2);
            clear_input_queue();
            Number1=append_data(Number1,number1);
            Operator=append_data(Operator,operator);
            Number2=append_data(Number2,number2);
            break;
        }
        case 'f':
        {
            Node *somenode1=NULL,*somenode2=NULL,*somenode3=NULL;
            int count1=0;
            count1=count(Number1);
            somenode1=find_node(Number1,count1);
            somenode2=find_node(Operator,count1);
            somenode3=find_node(Number2,count1);
            int number1,number2;
            char operator;
            printf("please enter an integer\n");
            scanf("%d",&number1);
            clear_input_queue();
            printf("please enter an operator\n");
            scanf("%c",&operator);
            clear_input_queue();
            printf("please enter an integer\n");
            scanf("%d",&number2);
            clear_input_queue();
            somenode1->data=number1;
            somenode2->data=operator;
            somenode3->data=number2;
            break;
        }
        case 'g':
        {
            int count1=0;
            count1=count(Number1);//由于3个链表一样长 取其中一个即可
            delete_midnode(Number1,count1);
            delete_midnode(Number2,count1);
            delete_midnode(Operator,count1);
            break;
        }
        case 'h': 
        {
            Node *nd1=Number1,*nd2=Operator,*nd3=Number2;
            int result=0;
            while (1)
            {
                if(nd1==NULL)break;
                if (nd2->data=='+')
                {
                    result=(nd1->data)+(nd3->data);
                }else if(nd2->data=='-')
                {
                    result=(nd1->data)-(nd3->data);
                }else if(nd2->data=='*')
                {
                    result=(nd1->data)*(nd3->data);
                }else if(nd2->data=='/')
                {
                    result=(nd1->data)/(nd3->data);
                }
                printf("%d%c%d=%d\n",nd1->data,nd2->data,nd3->data,result);
                if (nd1!=NULL)//三个链表长度相同故判断一个即可
                {
                    nd1=nd1->next;
                    nd2=nd2->next;
                    nd3=nd3->next;
                }
            }
            break;
        }
           
        case 'i':
        {
            int i,j;
            int result;
            printf("please enter row 1\n");
            scanf("%d",&row1);
            clear_input_queue();
            printf("please enter column1\n");
            scanf("%d",&column1);
            clear_input_queue();
            printf("please enter column2\n");
            scanf("%d",&column2);
            clear_input_queue();
            printf("enter first matrix %d*%d\n",row1,column1);
            for ( i = 0; i < row1; i++)
            {
                for(j=0;j<column1;j++){
                    scanf("%d",&result);
                    matrix1[i][j]=result;
                }
            }
            printf("enter second matrix %d*%d\n",column1,column2);
            for ( i=0; i<row1;i++)
            {
                for(j=0;j<column1;j++){
                    scanf("%d",&result);
                    matrix2[i][j]=result;
                }
            }
            clear_input_queue();
            matrix_multiply(row1,column1,column2,matrix1,matrix2,matrix3);
            break;
        }
        case 'j':
        {
            printf("the answer is -----------\n");
            int i,j;
            for ( i=0; i<row1; i++)
            {
                for(j=0;j<column2;j++){
                    printf("%d ",matrix3[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 'q':
        goto END;
        default:
            break;
        }
        show_menu();
        ch1=getchar();
        clear_input_queue();
    }
    END:
    free_list(Number1);
    free_list(Operator);
    free_list(Number2);
    puts("bye ~~~\n");
    return 0;
}
