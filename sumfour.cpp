#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
 
    
    
    
    
    long long array1[2501],array2[2501],array3[2501],subset1[6250001],subset2[6250002],array4[2501],i,j,n,count1=0,ans=0,counter1,counter2,sum,k;
            scanf("%lld",&n);
            for(i=0;i<n;i++)
                scanf("%lld%lld%lld%lld",&array1[i],&array2[i],&array3[i],&array4[i]);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    subset1[count1]=array1[i]+array2[j];
                    subset2[count1++]=array3[i]+array4[j];
                }
            }
            std::sort(subset1,subset1+count1);
            std::sort(subset2,subset2+count1);
            i=0;j=count1-1;
            while(i<count1&&j>=0)
            {
                sum=subset1[i]+subset2[j];
                k=i+1;
                counter1=1;
                while((subset1[i]==subset1[k])&&(k<count1))
                {
                    counter1++;
                    k++;
                }
                k=j-1;
                counter2=1;
                while((subset2[j]==subset2[k])&&k>=0)
                {
                    counter2++;
                    k--;
                }
                if(sum==0)
                {
                    ans+=counter1*counter2;
                    i=i+counter1;
                    j=j-counter2;
                }
                else if(sum>0)
                    j-=counter2;
                else
                    i+=counter1;
            }
            printf("%lld\n",ans);
            //system ("pause");
            return 0;
        } 