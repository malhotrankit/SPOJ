#include<stdio.h>
#include<math.h>
struct segsqrss
{
   long long num;
   long long square;
};
typedef struct segsqrss SEGSQRSS;
SEGSQRSS tree[400005];
long long array[100001],lazy[400005],updater[400005],l,r,diff,ans;
 
SEGSQRSS construct(long long si,long long ei,long long index)
{
    if(si==ei)
    {
        tree[index].num=array[si];
        tree[index].square=tree[index].num*tree[index].num;
        return tree[index];
    }
    SEGSQRSS a=construct(si,(si+ei)/2,index*2),b=construct((si+ei)/2+1,ei,index*2+1);
    tree[index].num=a.num+b.num;
    tree[index].square=a.square+b.square;
    return tree[index];
}
 
void update0(long long si,long long ei,long long index)
{
    if(lazy[index]!=0)
    {
        lazy[index]=0;
        updater[index]=0;
    }
    if(si>ei||si>r||ei<l)              
        return;
    if(si>=l&&ei<=r)
    {
        tree[index].square=(ei-si+1)*diff*diff;
        tree[index].num=(ei-si+1)*diff;
        if(si!=ei)
        {
            lazy[index*2]=diff;
            lazy[index*2+1]=diff;
            updater[index*2]=updater[index*2+1]=1;
        }
        return;
    }
    update0(si,(si+ei)/2,index*2);
    update0((si+ei)/2+1,ei,index*2+1);
    tree[index].num=tree[index*2].num+tree[index*2+1].num;
    tree[index].square=tree[index*2].square+tree[index*2+1].square;
}
  
void update1(long long si,long long ei,long long index)
{
    if(lazy[index]!=0)
    {
        if(updater[index]!=1)
        {    
            tree[index].square+=(ei-si+1)*lazy[index]*lazy[index]+2*lazy[index]*tree[index].num;
            tree[index].num+=(ei-si+1)*lazy[index];
            if(si!=ei)
            {
                lazy[index*2]+=lazy[index];                  
                lazy[index*2+1]+=lazy[index];                
            }
        }
        else
        {
            tree[index].square=(ei-si+1)*lazy[index]*lazy[index];
            tree[index].num=(ei-si+1)*lazy[index];
            if(si!=ei)
            {
                lazy[index*2]=lazy[index];
                lazy[index*2+1]=lazy[index];
                updater[index*2]=updater[index*2+1]=1;
            }
            updater[index]=0;
        }
        lazy[index]=0;                                  
    }
    if(si>ei||si>r||ei<l)              
        return;
    if(si>=l&&ei<=r)
    {
        tree[index].square+=(ei-si+1)*diff*diff+2*diff*tree[index].num;
        tree[index].num+=(ei-si+1)*diff;
        if(si!=ei)
        {
            lazy[index*2]+=diff;
            lazy[index*2+1]+=diff;
        }
        return;
    }
    update1(si,(si+ei)/2,index*2);
    update1((si+ei)/2+1,ei,index*2+1);
    tree[index].num=tree[index*2].num+tree[index*2+1].num;
    tree[index].square=tree[index*2].square+tree[index*2+1].square;
}
 
void query(long long si,long long ei,long long index)
{
    if(si>ei||si>r||ei<l)
        return;
    if(lazy[index]!=0)
    {
        if(updater[index]!=1)
        {    
            tree[index].square+=(ei-si+1)*lazy[index]*lazy[index]+2*lazy[index]*tree[index].num;
            tree[index].num+=(ei-si+1)*lazy[index];
            if(si!=ei)
            {
                lazy[index*2]+=lazy[index];                  
                lazy[index*2+1]+=lazy[index];                
            }
        }
        else
        {
            tree[index].square=(ei-si+1)*lazy[index]*lazy[index];
            tree[index].num=(ei-si+1)*lazy[index];
            if(si!=ei)
            {
                lazy[index*2]=lazy[index];
                lazy[index*2+1]=lazy[index];
                updater[index*2]=updater[index*2+1]=1;
            }
            updater[index]=0;
        }
        lazy[index]=0;
    }
    if(si>=l&&ei<=r)
    {
        ans=ans+tree[index].square;
        return;
    }
    query(si,(si+ei)/2,index*2);
    query((si+ei)/2+1,ei,index*2+1);
}
 
/*void display(int size)
{
    for(int i=1;i<=size;i++)
        printf("%lld**%lld ",tree[i].num,tree[i].square);
        //printf("%lld ",updater[i]);
        //printf("%lld ",lazy[i]);
    printf("\n");
}*/
 
int main(void) 
{
    long long n,i,ht,size,q,t,p,m;
    scanf("%lld",&t);
    m=1;
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        ht=(long long)ceil(log(n)/log(2));
        size=2*(long long)pow(2,ht)-1;
        for(i=1;i<=size;i++)
            updater[i]=lazy[i]=tree[i].num=tree[i].square=0;
        for(i=1;i<=n;i++)
            scanf("%lld",&array[i]);
        construct(1,n,1);
        printf("Case %lld:\n",m++);
        for(i=1;i<=q;i++)
        {
            scanf("%lld%lld%lld",&p,&l,&r);
            if(p==0)
            {
                scanf("%lld",&diff);
                update0(1,n,1);
            }
            else if(p==1)
            {
                scanf("%lld",&diff);
                update1(1,n,1);
            }
            else
            {
                ans=0;
                query(1,n,1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
} 