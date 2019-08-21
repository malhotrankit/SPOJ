#include<stdio.h>
long long array1[1001],array2[1001],matrix[1001][1001];
int main()
{
    long long i,j,n,m,t,max,check,flag;
    scanf("%lld",&t);
    while(t--)
    {
        n=1;max=0;
        scanf("%lld",&flag);
        while(flag)
        {
            array1[n++]=flag;
            scanf("%lld",&flag);
        }
        --n;
        //printf("n= %lld\n",n);
        scanf("%lld",&check);
        while(check)
        {
            m=1;
            flag=check;
            while(flag)
            {
                array2[m++]=flag;
                scanf("%lld",&flag);
            }
            --m;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    if(array1[i]==array2[j])
                        matrix[i][j]=matrix[i-1][j-1]+1;
                    else
                    {
                        if(matrix[i-1][j]>matrix[i][j-1])
                            matrix[i][j]=matrix[i-1][j];
                        else
                            matrix[i][j]=matrix[i][j-1];
                    }
                }
            }
            if(max<matrix[n][m])
                max=matrix[n][m];
            /*for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    printf("%lld ",matrix[i][j]);
                }
                printf("\n");
            }*/
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                {
                    matrix[i][j]=0;
                }
            }
            scanf("%lld",&check);
        }
        printf("%lld\n",max);
    }
    return 0;
} 