#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

typedef struct
{
    int row,column;
    double value;
} matrice;
//****function section****//
void INputMatrix(matrice matrix[]);
void OUTputMatrix(matrice matrix[]);
int InverseMatrix(matrice matrix[],matrice matrix_inverse[]);
void fastTranspose(matrice matrixA[],matrice matrixB[]);
double MatrixCofactors(matrice matrix[],int row,int column);
double determinant(matrice matrix[]);
double Gaussian(matrice matrix[]);
void makeValue(matrice matrix[],int column,int raw);
void Rawdivide(matrice matrix[],int row,double divisor);
int searchPosition(matrice matrix[],int column,int row);
void AddRaw(matrice matrix[],int rowA,int rowB,double coef);
//****function section****//
//****function for test section****//
void OUTputMatrixForTest(matrice matrix[])
{
    int i,j,Pos;
    for(i=1; i<=matrix[0].row; i++)
    {
        for(j=1; j<=matrix[0].column; j++)
        {
            Pos=searchPosition(matrix,j,i);
            if(Pos)printf("%10.3lf ",matrix[Pos].value);
            else printf("%10d ",Pos);
        }
        printf("\n");
    }
}
//****function for test section****//
int main(void)
{
    matrice matrix[MAX],matrix_inverse[MAX];
    freopen("testFor_fTp1.txt","r",stdin);
    INputMatrix(matrix);
    if(InverseMatrix(matrix,matrix_inverse))
        OUTputMatrix(matrix_inverse);
    else printf("The matrix is non-invertible.\n");
    //OUTputMatrixForTest(matrix_inverse);
}


//****function section****//
void INputMatrix(matrice matrix[])
{
    int i;
    scanf("%d%d%lf",&matrix[0].row,&matrix[0].column,&matrix[0].value);
    for(i=1; i<=matrix[0].value; i++)
    {
        scanf("%d%d%lf",&matrix[i].row,&matrix[i].column,&matrix[i].value);
        matrix[i].row++;
        matrix[i].column++;
    }
    return;
}
void OUTputMatrix(matrice matrix[])
{
    int i;
    for(i=1; i<=matrix[0].value; i++)printf("%d %d %lf\n",matrix[i].row,matrix[i].column,matrix[i].value);

}
int InverseMatrix(matrice matrix[],matrice matrix_inverse[])
{
    matrice sub_matrix[MAX],sub_matrix1[MAX];
    int i,j,k=1,value;
    double det=determinant(matrix);
    memcpy(sub_matrix,matrix,sizeof(matrice)*MAX);
    memcpy(sub_matrix1,matrix,sizeof(matrice));
    if(abs(det)<0.000001)return 0;
    for(i=1; i<=matrix[0].row; i++)
        for(j=1; j<=matrix[0].column; j++)
        {
            value=MatrixCofactors(matrix,i,j);
            if(value)
            {
                sub_matrix1[k].row=i;
                sub_matrix1[k].column=j;
                sub_matrix1[k].value=value/det;
                k++;
            }
        }
    sub_matrix1[0].value=k-1;
    fastTranspose(sub_matrix1,matrix_inverse);
    return 1;
}
void fastTranspose(matrice matrixA[],matrice matrixB[])
{
    int rowTerms[MAX],startingPos[MAX];
    int i,j;
    memcpy(matrixB,matrixA,sizeof(matrice));
    if(matrixA[0].value<0)return;
    memset(rowTerms,0,sizeof(rowTerms));
    for(i=1; i<=matrixB[0].value; i++)rowTerms[matrixA[i].column]++;
    startingPos[0]=1;
    for(i=1; i<=matrixA[0].column; i++)startingPos[i]= startingPos[i-1]+rowTerms[i-1];
    for(i=1; i<=matrixB[0].value; i++)
    {
        j=startingPos[matrixA[i].column]++;
        matrixB[j].row=matrixA[i].column;
        matrixB[j].column=matrixA[i].row;
        matrixB[j].value=matrixA[i].value;
    }
    return;
}
double MatrixCofactors(matrice matrix[],int row,int column)
{
    matrice sub_matrix[MAX];
    int i,j=1;
    for(i=1; i<=matrix[0].value; i++)
        if(row!=matrix[i].row && column!= matrix[i].column)
        {
            sub_matrix[j].row= matrix[i].row;
            sub_matrix[j].column= matrix[i].column;
            sub_matrix[j].value= matrix[i].value;
            if(sub_matrix[j].row>row)sub_matrix[j].row--;
            if(sub_matrix[j].column>column)sub_matrix[j].column--;
            j++;
        }
    sub_matrix[0].value=j-1;
    sub_matrix[0].row=matrix[0].row-1;
    sub_matrix[0].column=matrix[0].column-1;
    j=0;
    if((row+column)&1)return -determinant(sub_matrix);
    return determinant(sub_matrix);
}
double determinant(matrice matrix[])
{
    int i,j=1;
    double det;
    matrice sub_matrix[MAX];
    memcpy(sub_matrix,matrix,sizeof(matrice)*MAX);
    det=Gaussian(sub_matrix);/*sub_matrix will change*/
    for(i=1; i<=sub_matrix[0].value; i++)
        if(sub_matrix[i].column == sub_matrix[i].row)
        {
            det*=sub_matrix[i].value;
            j++;
        }
    if(j<sub_matrix[0].column)det=0;
    return det;
}
double Gaussian(matrice matrix[])
{
    int i,j,coef,Pos;
    double GAS=1;
    for(i=matrix[0].column; i>1; i--)
    {
        if(searchPosition(matrix,i,i)==0)makeValue(matrix,i,i);
        if(searchPosition(matrix,i,i)==0)return 0;
        Pos=searchPosition(matrix,i,i);
        GAS*=matrix[Pos].value;
        Rawdivide(matrix,i,matrix[Pos].value);
        for(j=i-1; j>=1; j--)
            AddRaw(matrix,j,i,-matrix[searchPosition(matrix,i,j)].value);/*matrix will change*/
    }
    return GAS;
}
void makeValue(matrice matrix[],int column,int raw)
{
    int i;
    for(i=1; i<= matrix[0].column; i++)
        if(matrix[i].column==column)
        {
            AddRaw(matrix,raw,matrix[i].row,1);
            return;
        }
}
void Rawdivide(matrice matrix[],int row,double divisor)
{
    int i;
    for(i=1; i<=matrix[0].value; i++)
        if(matrix[i].row==row)matrix[i].value/=divisor;
    return;
}
int searchPosition(matrice matrix[],int column,int row)
{
    int i;
    for(i=1; i<=matrix[0].value; i++)
        if(matrix[i].row==row && matrix[i].column==column)return i;
    return 0;
}
void AddRaw(matrice matrix[],int rowA,int rowB,double coef)
{
    matrice sub_matrix[MAX];
    int i,j=1,Pos;
    for(i=1; i<=matrix[0].value; i++)
        if(matrix[i].row==rowB)
        {
            Pos=searchPosition(matrix,matrix[i].column,rowA);
            if(!Pos)
            {
                matrix[0].value++;
                matrix[(int)matrix[0].value].column=matrix[i].column;
                matrix[(int)matrix[0].value].row=rowA;
                matrix[(int)matrix[0].value].value=matrix[i].value*coef;
            }
            else
            {
                matrix[Pos].value+=(matrix[i].value*coef);
            }
        }
    return;
}
//****function section****//
