#include  <stdio.h>
long long matrix[1001][100001];
int main()
{
    long long i,j,n,sum,array[10001],t;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&array[i]);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=100000;j++)
            {
                if(matrix[i-1][j]==1)
                {
                   matrix[i][j+array[i]]=1;
                   matrix[i][j]=1;
                }
            }
            matrix[i][array[i]]=1;
        }
        for(i=1;i<=100000;i++)
            if(matrix[n][i]==1)
                sum=sum+i;
        for(i=1;i<=n;i++)
            for(j=1;j<=100000;j++)
                matrix[i][j]=0;
        printf("%lld\n",sum);
    }
    return 0;
} 