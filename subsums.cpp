#include<iostream>
#include<algorithm>
 
using namespace std;
 
long long cmpfunc(const void*a,const void*b)
{
   return(*(long long*)a-*(long long*)b);
}
 
long long x[1048577],y[1048577],array[41];
 
int main()
{
    long long i,j,sum,n,a,b,p,q=0,count=0,*low,*up,ans=0,w=0;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(i=0;i<n/2;i++)
    {
        scanf("%lld",&p);
        count=q;
        for(j=0;j<count;j++)
        {
            x[q++]=p+x[j];
            if(a<=p+x[j]&&p+x[j]<=b)
                ans++;
        }
        x[q++]=p;
        if(a<=p&&p<=b)
            ans++;
    }
    /*for(i=0;i<q;i++)
        printf("%lld ",x[i]);*/
    count=0;
    for(i=n/2;i<n;i++)
    {
        scanf("%lld",&p);
        count=w;
        for(j=0;j<count;j++)
        {
            y[w++]=p+y[j];
            if(a<=p+y[j]&&p+y[j]<=b)
                ans++;
        }
        y[w++]=p;
        if(a<=p&&p<=b)
            ans++;
    }
    if(a<=0&&0<=b)
        ans++;
    std::sort(y,y+w);
    /*for(i=n/2;i<n;i++)
        printf("%lld ",y[i]);*/
    for(i=0;i<q;i++)
    {
        low=std::lower_bound(y,y+w,a-x[i]);
        up=std::upper_bound(y,y+w,b-x[i]);
        ans+=(up-(y+(w)))-(low-(y+(w)));
    }
    printf("%lld\n",ans);
    return 0;
    
} 