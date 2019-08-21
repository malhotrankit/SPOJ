#include <iostream>
 
int matrix[51][50001],count[50001],array[51];
 
int main()
{
    int t,i,j,k,n,sum,max,pos;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        max=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&array[i]);
            sum+=array[i];
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                for(k=1;k<=sum;k++)
                {
                    if(matrix[j][k]!=i&&matrix[j][k]>0)
                    {
                        if(matrix[j+1][k+array[i]]==0)
                        {
                            matrix[j+1][k+array[i]]=i;
                            count[k+array[i]]++;
                        }
                    }
                }
            }
            if(matrix[1][array[i]]!=1)
            {
                matrix[1][array[i]]=1;
                count[array[i]]++;
            }
       }
       for(i=1;i<=sum;i++)
       {
           for(j=1;j<=n;j++)
           {
               matrix[j][i]=0;
           }
           if(max<count[i])
           {
               max=count[i];
               pos=i;
           }
           count[i]=0;
       }
       printf("%d %d\n",max,pos);
    }
    return 0;
} 
