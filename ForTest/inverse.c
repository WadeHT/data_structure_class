#include <stdio.h>
#include<stdlib.h>
int main()
{
    int s, i, j, k,row = 7, col = 7;
    float det = 1, t, a[100][100] = { {0},{0} }, b[100][100] = { { 0 },{ 0 } },c[100][100] = { { 0 },{ 0 } };
    a[0][0] = 15;a[0][3] = 22;a[0][5] = -15;a[1][1] = 11;a[1][2] = 3;a[2][3] = -6;a[4][0] = 91;a[5][2] = 28;a[6][6] = 8;
    for (i = 0; i < row; i++)for (j = 0; j < col; j++)b[i][j] = (i==j)?1:0;
    for (k = 0; k < row; k++)
    {
        t = 0;
        for (j = 0; j < row; j++)t += a[k][j];
        if (t == 0)
        {
            printf("The matrix is non - invertible.");
            return 0;
        }
        if (a[k][k] != 1)for (i = 0; i < row; i++)
            {
                a[k][i] = a[k][i] / a[k][k];
                b[k][i] = b[k][i] / a[k][k];
            }
        for (i = 0; i < row; i++)if (a[i][k] != 0 && i != k)for (j = 0; j < col; j++)
                {
                    a[i][j] = a[i][j] - (a[k][j] * a[i][k]);
                    b[i][j] = b[i][j] - (b[k][j] * a[i][k]);
                }
    }
    for (i = 0; i < row; i++)for (j = 0; j < col; j++)printf("row=%d col=%d %.2f\n", b[i][j]);
}
