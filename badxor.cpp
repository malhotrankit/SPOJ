#include<stdio.h>
long long calculate[1024],previous[1024];
int main()
{
    long long t,n,m,i,j,chk,count,k;
    scanf("%lld",&t);
    for(k=1;k<=t;k++)
    {
        count=0;
        scanf("%lld%lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&chk);
            for(j=0;j<=1023;j++)
            {
                if(previous[j]>0)
                {
                    calculate[j^chk]+=previous[j];
                    calculate[j^chk]=calculate[j^chk]%100000007;
                } 
            }
            calculate[chk]+=1;
            calculate[chk]==calculate[chk]%100000007;
            for(j=0;j<=1023;j++)
                previous[j]=calculate[j];
        }
        calculate[0]+=1;
        for(i=0;i<m;i++)
        {
            scanf("%lld",&chk);
            calculate[chk]=0;
        }
        for(i=0;i<=1023;i++)
        {
            count=count+calculate[i]; 
            count=count%100000007;
            calculate[i]=0;
            previous[i]=0;
        }
        printf("Case %lld: %lld\n",k,count);
    }
    return 0;
} 