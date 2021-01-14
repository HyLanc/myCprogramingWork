#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<float.h>
#include<string.h>
int holiday[12][31];//声明全局数组默认初始化为0
int isyear(int year){
    if(year%4==0&&year%100!=0||year%400==0){
        return 1;
    }
    else
        return 0;
}
//判斷是否是閏年的函數
void show_n_char(char ch, int num) {
	int count; 
	for (count = 1; count <= num; count++) 
		putchar(ch); 
} 
// 使菜單看起來整齊的函數
int all_day(int y ,int m)
 {
     int flag = 0;//存儲是否是閏年
     int day = 30;

     if (isyear(y)==1)
     {
         flag = 1;
     }

     if ((m == 1) || (m == 3) || (m == 5) || (m == 7)
         || (m == 8) || (m == 10) || (m == 12))
     {
         day = 31;
     }

     else if ((m == 2) && (flag == 1))
     {
         day = 29;
     }

     else if ((m == 2) && (flag == 0))
     {
         day = 28;
     }
     else
         day = 30;

     return day;

 }
//計算當月縂天數的函數
 int Calculate(int y, int m)
{
    int sy = 1;//設定基準年份為1912 why？ 因爲 1912第一天是周一 且中國是從1912年開始使用公元
    int i = 0;
    int sum = 0;//用来保存所输入的日期与基准相差的天数

    for (i = sy; i < y; i++)
    {
        if (isyear(i)==1)
        {
            sum = sum + 366;
        }
        else
            sum = sum + 365;
    }//计算出年份与基准年份相差的天数
    for (i = 1; i < m; i++)
    {

        if ((i == 1) || (i == 3) || (i == 5) || (i == 7)
            || (i == 8) || (i == 10) || (i == 12))
        {
            sum = sum + 31;
        }

        else if ((i == 2) && (isyear(y)== 1))
        {
            sum = sum + 29;
        }

        else if ((i == 2) && (isyear(y) == 0)) 
        {
            sum = sum + 28;
        }
        else
            sum = sum + 30;

    }
        return sum%7+1;//比基準年份大加一 且由於基準年份第一天為周一 故算出來時1-7對於周一到周日
}
//此函數返回值是當前月份第一天是周幾
int Calculate2(int y,int m,int d){
    int sy=1;
    int sum=0;
    int i=0;
     for (i = sy; i < y; i++)
    {
        if (isyear(i)==1)
        {
            sum = sum + 366;
        }
        else
            sum = sum + 365;
    }//计算出年份与基准年份相差的天数
    for (i = 1; i < m; i++)
    {

        if ((i == 1) || (i == 3) || (i == 5) || (i == 7)
            || (i == 8) || (i == 10) || (i == 12))
        {
            sum = sum + 31;
        }

        else if ((i == 2) && (isyear(y)== 1))
        {
            sum = sum + 29;
        }

        else if ((i == 2) && (isyear(y) == 0)) 
        {
            sum = sum + 28;
        }
        else
            sum = sum + 30;
    }
    for(i=1;i<d;i++)sum+=1;
     return sum%7+1;
}
//此函數返回目標年份與所需要年份的差距
void print(int month, int week, int day)
{
    int i = 0;
    int date = 1;
    int flag = week;//week為當月1號是星期几是通過上一個函數算出的；
    printf("SUN MON TUE WED THU FRI SAT\n");
    for (i = 0; i <6; i++)//day+week來判斷這個月一共有幾周 來判斷循環幾次
    {
        int j = 0;
        int k = 0;

        for (j = 0; j <week; j++)
        {   
            if (week==7)
        {
            week=0;
            flag=0;
        }
        
            if (flag != 0)
            {
                printf("    ");
            }

            flag--;
        }
        for (k = 0; k < 7 - week; k++)
        {
            if (date > day)
            {
                break;
            }
            if(holiday[month][date]==1)
            {
                printf(" *%2d ", date);
            }
            else printf(" %2d ",date);
            date++;
        }
        week = 0;//儅第一行運行結束后 就無需基準日期的判斷 故取0 以免影響後續
        printf("\n");
    }
}
int main(void){
    int year,month,week,day;
    int i=1;
    printf("Please type a character to make a choice\n");
    printf("a: Print the calendar of a month\n");
    printf("b: Print the calendar of a year\n");
    printf("c: Tell the weekday for a given day\n");
    printf("d: Record a holiday\n");
    printf("e: Print all the holidays of the year\n");
    printf("q: Quit the program\n");
    char ch;
    ch=getchar();
    while(ch!='q'){
         while (getchar()!='\n')//輸入完進行清除緩衝區
           {
            continue;
           }
        switch (ch)
        {
        case 'a':
            printf("enter year and month please\n");
            scanf("%d%d",&year,&month);
             while (getchar()!='\n')//輸入完進行清除緩衝區
            {
             continue;
            }
            day=all_day(year,month);
            week=Calculate(year,month);
            print(month,week,day);
            break;
        case 'b':
            printf("enter the year you need\n");
            scanf("%d",&year);
            while (getchar()!='\n')//輸入完進行清除緩衝區
            {
             continue;
            }
            while(i<=12)
            {
                day=all_day(year,i);
                week=Calculate(year,i);
                printf("-------------------%d %d------------------\n",year,i);
                print(i,week,day);
                i++;
            }
            i=1;
            break;
        case 'c':
        {
            int exatday;
            printf("please enter the year month day you want to know is exat day\n");
            scanf("%d%d%d",&year,&month,&day);
            while (getchar()!='\n')//輸入完進行清除緩衝區
            {
            continue;
            }
            exatday=Calculate2(year,month,day);
            switch (exatday)
            {
            case 1:
                printf("this day is Monday\n");
                break;
            case 2:
                printf("this day is Tuesday\n");
                break;
            case 3:
                printf("this day is Wednesday\n");
                break;
            case 4:
                printf("this day is Thursday\n");
                break;
            case 5:
                printf("this day is Friday\n");
                break;
            case 6:
                printf("this day is Saturday\n");
                break;
            case 7:
                printf("this day is Sunday\n");
                break;
            default:
                break;
            }
            break;
        } 
        case 'd':
        {
            int m,d;//儲存輸入的月份和幾號
            printf("please enter y to ensure that you want to record holiday\n");
            while(getchar()!='q'){
                printf("please enter month and day for your holiday\n");
                scanf("%d%d",&m,&d);
                while (getchar()!='\n')//輸入完進行清除緩衝區
            {
                continue;
            }
                holiday[m][d]=1;
                printf("enter y to continue or q to quit\n");
        }
                break;
        }
        case 'e':
        {
            printf("these are all of the holiday you enter\n");
            int i=0;
            int j=0;
            for(i=1;i<=12;i++){
                for(j=1;j<=31;j++){
                    if(holiday[i][j]==1){
                        printf("%d  %d\n",i,j);
                    }
                }
            }
        }
            break;
        default:
            printf("sorry,I only accpet words like \"a,b,c,d\"\n");
            printf("enter again please\n");
            break;
        }
        printf("press any word to continue (tips: only one word plz )\n");
        getchar();//使程序暫停 按下任意按鍵繼續 目的是使得用戶能夠看清楚 自己想要的輸出結果
         while (getchar()!='\n')//輸入完進行清除緩衝區
        {
            continue;
        }
        show_n_char('*',40);
        putchar('\n');
        printf("Please type a character to make a choice\n");
        printf("a: Print the calendar of a month\n");
        printf("b: Print the calendar of a year\n");
        printf("c: Tell the weekday for a given day\n");
        printf("d: Record a holiday\n");
        printf("e: Print all the holidays of the year\n");
        printf("q: Quit the program\n");
        ch=getchar();
    }
    printf("good bye!~~~~\n");
    return 0;
}




