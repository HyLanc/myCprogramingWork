#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
void matrix_multiply(int row1,int column1,int column2,int matrix1[MAX][MAX],int matrix2[MAX][MAX],int matrix3[MAX][MAX]){
    int i, j, k;
    int result;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < column1; j++)
        {
            result = 0;
            for (k = 0; k < column2; k++)
            {
                result += matrix1[i][k] * matrix2[k][j];   //按照矩阵的乘法规则进行运算
            }
            matrix3[i][j] = result;
        }
    }
}
