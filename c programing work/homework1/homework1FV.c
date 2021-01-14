#include<stdio.h>
#include<math.h>
#include<float.h>
#define AIM_OF_PRECISION 3.14159
#define MAX_TERM_NUM 10000
#define TRUE_PI 3.1415926535897932384626
//this program is written by 何雨宸 CS110 D1
//vs code is better than notepad 
//此函數用計算 EULER1 公式的pi值
double ESS1(int a){
    int i=1;
    double ss1=0;
    while (i<=a)
    {
        ss1=ss1+1/pow(i,2);
        i++;
    }
    ss1=sqrt(6*ss1);
    return ss1;
}
//此函數用於計算 EULER2 公式的pi值
double ESS2(int a){
    int i=1;
    double ss2=0;
    while (i<=a)
    {
        ss2=ss2+1/pow(2*i-1,2);
        i++;
    }
    ss2=sqrt(8*ss2);
    return ss2;
}
//此函数为计算阶乘的函数 用以最后一个公式使用
double sum(int n){
    int i;
    int sum=1;
    for(i=1;i<=n;i++){
        sum*=i;
    }
    return (double)sum;//返回雙精度浮點用於公式計算
}
 //此函數為冒泡排序 用於排列各個公式計算出來的精確度大小
 void bubble_sort(double arr[], int len) {
        int i, j;
        double temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1]) {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
}
int main (void){
    printf("hello! what's your name ?\n");
    char name[10];
    scanf("%s",name);
    printf("hello %s, we are going to compute how many terms are needed to compute PI\n",name);
    printf("to reach the precision 3.14159 before 10000 terms\n");//我直接設置3.14159 和 10000terms 為我的目標
    printf("here are the results\n");
    double GGS,NS,AS,SS1,SS2,RS;//存儲各個公式算出的pi值
    double  POFFORMULA[6];//LEFT OF XXX存儲與真實pi值相減的值來比較精確度
    int TERMOFGGS,TERMOFNS,TERMOFAS,TERMOFSS1,TERMOFSS2,TERMOFRS;//存儲項數
    double i;
    GGS=0;
    for(i=1;i<=MAX_TERM_NUM;i++){
        if((int)i%2==0)GGS=GGS-1/(2*i-1);
        else
            GGS=GGS+1/(2*i-1);
            TERMOFGGS=(int)i;
        //if語句進行比較用以判斷是否pi值到達了我們所需要的精確度
        if((4*GGS)>=AIM_OF_PRECISION && (4*GGS)<3.1416){ 
            break;
        }
    }
    GGS=4*GGS;
    POFFORMULA[0]=fabs(GGS-TRUE_PI);//將pi的精確度保留進數組中
    printf("GGS   %.15f   %10d      endless\n",GGS,TERMOFGGS);//此為第一個公式所算出的pi值和項數，所有pi均在收斂至AIM OF PRECISION或到達MAX TERM 后結束并且記錄項數輸出
    NS=0;
    int count=1;//用於方便控制奇偶數項的正負，簡化代碼不使用if語句
    double j=2;
    while (j<=MAX_TERM_NUM*2){
        NS=NS+(4.0*(double)count)/(j*(j+1.0)*(j+2.0));
        count=-count;
        TERMOFNS=(int)j/2;
        j+=2;
        if((3.0+NS)>=AIM_OF_PRECISION&&(3.0+NS)<3.1416){
            break;
        }
    }
    NS=3.0+NS;
    POFFORMULA[1]=fabs(NS-TRUE_PI);//將pi的精確度保留進數組中
    printf("NS    %.15f   %10d      success\n",NS,TERMOFNS);//此為第二個公式的輸出 pi 和 項數
    AS=0;
    double k=0;
    do{
        AS=AS+(2*pow(-1,k)*pow(3,0.5-k))/(2*k+1);
        TERMOFAS=(int)k+1;//这里加1是因为从0项开始为了保持一致把0项当作第一项
        if(AS>=AIM_OF_PRECISION&&AS<3.1416){
           break;
       }
       k++;
    } while (k<=MAX_TERM_NUM);
    POFFORMULA[2]=fabs(AS-TRUE_PI);//將pi的精確度保留進數組中
    printf("AS    %.15f   %10d      success\n",AS,TERMOFAS);
    SS1=ESS1(MAX_TERM_NUM);
    POFFORMULA[3]=fabs(SS1-TRUE_PI);
    TERMOFSS1=MAX_TERM_NUM;
    //在這裏直接令SS1的項數直接為10000的原因是因爲程序的運行結果無法收斂到所需要的精度，
    //所以一定超過10000項。且我們只需要10000項内的計算，故將TERMOFSS1記入10000
    printf("SS1   %.15f   %10d      endless\n",SS1,TERMOFSS1);
    SS2=ESS2(MAX_TERM_NUM);
    POFFORMULA[4]=fabs(SS2-TRUE_PI);//將pi的精確度保留進數組中
    TERMOFSS2=MAX_TERM_NUM;
    //这里直接赋值的原因同上 此公式在10000项数内无法收敛至我所需要的精度
    printf("SS2   %.15f   %10d      endless\n",SS2,TERMOFSS2);
    RS=0;
    double n=0;
    while (n<=MAX_TERM_NUM)
    {
        RS=RS+(sum(4*n)/pow(sum(n),4))*(26390*n+1103)/pow(396,4*n);
        TERMOFRS=(int)n+1;//加1的理由同上
        n++;
        if(pow(RS*(sqrt(8)/9801),-1)>=AIM_OF_PRECISION&&pow(RS*(sqrt(8)/9801),-1)<3.1416)
        {
            break;
        }
    }
    RS=pow(RS*(sqrt(8)/9801),-1);
    POFFORMULA[5]=fabs(RS-TRUE_PI);//將pi的精確度保留進數組中
    printf("RS    %.15f   %10d      success\n",RS,TERMOFRS);
    printf("now we are going to print the precision of each formula from high to low\n");
    int len;//數組長度
    len =(int)sizeof(POFFORMULA)/sizeof(*POFFORMULA);
    int p;//用於下面的for循環輸出數組POFFORMULA
    for ( p = 0; p < len; p++)
    {
        printf("%d    %.15lf\n",p+1,POFFORMULA[p]);//按順序輸出 從1到6 分別代指 從GGS到RS 
    }
    bubble_sort(POFFORMULA,len);
    printf("next is the precision of rearrangement\n");
    for ( p = 0; p < len; p++)
    {
        printf("    %.15lf\n",POFFORMULA[p]);//輸出排序過後的精確度排行由小到大 
    }
    printf("so we can know that the most presicion formula is Ramanujan formula\n");
    printf("and we can know that the fastest formula is one of Ramanujan formula\n");
    printf("it use only 1 term to achieve the percision we need\n");
    printf("Then we got the champion formula \"Ramanujan formula\"");
    return 0;
}
 