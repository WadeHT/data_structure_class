#include <stdio.h>
int T = 0;
void H(int n, char A, char B, char C)
{
    if (n == 1)printf("%d : ���� %c �� %c\n",++T,A,C);
    else
    {
        H(n - 1, A, C, B);
        H(1, A, B, C);
        H(n - 1, B, A, C);
    }
}
int main()
{
    H(12, 'A','B','C');
    printf("�@���� %d ��\n",T);
}
