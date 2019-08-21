                                                                    /*Segment Tree*/
#include<stdio.h>
#include<string.h>
#include<math.h>
struct tree
{
	long long sum;
	long long min;
};
typedef struct tree TREE;
TREE *courage;
int l,r,n,y;
long long *array,x,ans;
long long minimum(long long a,long long b)
{
    if(a>=b)
            return b;
    else
            return a;
}
TREE construct(int si,int ei,int index)
{
	if(si==ei)
	{
		courage[index].min=courage[index].sum=array[si];
		return (courage[index]);
	}
	TREE a=construct(si,(si+ei)/2,index*2),b=construct((si+ei)/2+1,ei,index*2+1);
    courage[index].sum=a.sum+b.sum;
    courage[index].min=minimum(a.min,b.min);
	return (courage[index]);
}
long long count(int si,int ei,int index)
{
	if(r<si||l>ei)
		return 100000000000001;
	if(si>=l&&ei<=r)
    {
        ans=ans+courage[index].sum;
        return courage[index].min;
    }
    return(minimum(count(si,(si+ei)/2,index*2),count((si+ei)/2+1,ei,index*2+1)));
}
long long update(int si,int ei,int index)
{
	if(y<si||y>ei)
		return courage[index].min;
    courage[index].sum=courage[index].sum+x;
    if(si!=ei)
        courage[index].min=minimum(update(si,(si+ei)/2,index*2),update((si+ei)/2+1,ei,index*2+1));
    if(si==ei)
        courage[index].min=courage[index].sum;
    return (courage[index].min);
}
int main()
{
	int q,i,ht,size;
    long long min;
    char query[6];
	scanf("%d",&n);
	array = new long long[n+1];
	for(i=1;i<=n;i++)
		scanf("%lld",&array[i]);
	ht=(int)ceil(log(n)/log(2));
	size=2*(int)pow(2,ht)-1;
	courage=new TREE[size+1];
	construct(1,n,1);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%s",query);
        if(query[0]=='C')
        {
            ans=0;
            scanf("%d%d",&l,&r);
            l++;
            r++;
            min=count(1,n,1);
            printf("%lld\n",ans-min);
        }
        else if(query[0]=='E')
        {
            scanf("%lld%d",&x,&y);
            y++;
            x=-1*x;
            update(1,n,1);
        }
        else
        {
            scanf("%lld%d",&x,&y);
            y++;
            update(1,n,1);
        }
    }
    return 0;
} 