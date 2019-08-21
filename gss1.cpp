#include<stdio.h>
#include<math.h>
struct GSS1
{
    long long lmax=0;
    long long tmax=0;
    long long rmax=0;
    long long sum=0;
};
typedef struct GSS1 TREE;
int *array,l,r,count;
TREE *tree,*x;
long long max(long long a,long long b,long long c,long long d)
{
    if(a>=b&&a>=c&&a>=d)
        return a;
    else if(b>a&&b>=c&&b>=d)
        return b;
    else if(c>a&&c>b&&c>=d)
        return c;
    else 
        return d;
}
TREE construct(int si,int ei,int index)
{
	if(si==ei)
    {
		tree[index].lmax=tree[index].tmax=tree[index].rmax=tree[index].sum=array[si];
        return tree[index];
    }
    TREE a=construct(si,(si+ei)/2,index*2),b=construct((si+ei)/2+1,ei,index*2+1);
    tree[index].lmax=max(a.lmax,a.sum+b.lmax,a.sum+b.sum,-750350001);
    tree[index].rmax=max(b.rmax,a.rmax+b.sum,a.sum+b.sum,-750350001);
    tree[index].tmax=max(a.tmax,b.tmax,a.sum+b.sum,a.rmax+b.lmax);
    tree[index].sum=a.sum+b.sum;
    return(tree[index]);
    
}
void query(int si, int ei, int index)
{
    if (l <= si && r >= ei)
    {
        x[count++]=tree[index];
        return;
    }
    if (ei < l || si > r)
        return;
    query(si,(si+ei)/2,index*2);
    query((si+ei)/2+1,ei,index*2+1);
}
/*void display(int size)
{
    for(int i=1;i<=size;i++)
        printf("%lld**%lld**%lld**%lld\n",tree[i].lmax,tree[i].tmax,tree[i].rmax,tree[i].sum);
    printf("\n");
}*/
int main(void) 
{
    int n,i,ht,size,q,j;
    scanf("%d",&n);
    array=new int[n+1];
	for(i=1;i<=n;i++)
        scanf("%d",&array[i]);
	ht=(int)ceil(log(n)/log(2));
	size=2*(int)pow(2,ht)-1;
	tree=new TREE[size+1];
    x=new TREE[size+1];
	construct(1,n,1);
    //display(size);
    scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
        count=0;
        scanf("%d%d",&l,&r);
        query(1,n,1);
        for(j=1;j<count;j++)
        {
            x[j].tmax=max(x[j-1].tmax,x[j].tmax,x[j-1].sum+x[j].sum,x[j-1].rmax+x[j].lmax);
            x[j].lmax=max(x[j-1].lmax,x[j-1].sum+x[j].lmax,x[j-1].sum+x[j].sum,-750350001);
            x[j].rmax=max(x[j].rmax,x[j-1].rmax+x[j].sum,x[j-1].sum+x[j].sum,-750350001);
            x[j].sum=x[j-1].sum+x[j].sum;
        }
        printf("%lld\n",x[j-1].tmax);
    }        
	return 0;
} 