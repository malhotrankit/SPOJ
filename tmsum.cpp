#include<iostream>
#include<stdlib.h>
 
int cmpfunc(const void*a,const void*b)
{
   return(*(int*)a -*(int*)b);
}
 
int main()
{
    int count1,count2,sum1,sum2,i,p,negative[101],positive[101],n,t,one,zero;
    scanf("%d",&t);
    while(t--)
    {
        count1=0;
        count2=0;
        one=0;
        zero=0;
        sum1=0;
        sum2=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&p);
            if(p>1)
                positive[count1++]=p;
            if(p<0)
                negative[count2++]=p;
            if(p==1)
                one=1;
            if(p==0)
                zero=1;
        }
        //printf("%d ",count1);
        if(count1>0)
        {
            qsort(positive,count1,sizeof(int),cmpfunc);
            if(count1%2==0)
            {
                for(i=0;i<count1;i+=2)
                    sum1+=positive[i]*positive[i+1];
            }
            else
            {
                for(i=1;i<count1;i+=2)
                    sum1+=positive[i]*positive[i+1];
                //printf("s=%d ",sum1);
                sum1+=positive[0];
            }
        }
        if(one)
            sum1+=1;
        if(count2>0)
        {
            qsort(negative,count2,sizeof(int),cmpfunc);
            if(count2%2==0)
            {
                for(i=0;i<count2;i+=2)
                    sum2+=negative[i]*negative[i+1];
            }
            else
            {
                for(i=0;i<count2-1;i+=2)
                    sum2+=negative[i]*negative[i+1];
                if(zero==0)
                    sum2+=negative[count2-1];
            }
        }
        printf("%d\n",sum1+sum2);
    }
    return 0;
} 