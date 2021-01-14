#include<stdio.h>
#include"mystrCypher.h"
int mycypher(char arr[],unsigned int arrlen,unsigned int history[]){
     for(int i=0; i<arrlen-1; i++)
    {
        int min_index = i; 
        
        for(int j=i+1; j<arrlen; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        //将第i小的数，放在第i个位置；如果刚好，就不用交换
        if( i != min_index)
        {
            char temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            history[i]=min_index;
        }
    }
    return 0;
}