#include  <stdio.h>
int main(void)
{
    long long n,array[100001],calculate[1000001],i,maxlength=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&array[i]);
        if(calculate[array[i]-1]!=0)
            calculate[array[i]]=calculate[array[i]-1]+1;
        else
            calculate[array[i]]=1;
        if(maxlength<calculate[array[i]])
            maxlength=calculate[array[i]];
    }
    printf("%lld\n",maxlength);
    return 0;
} 
