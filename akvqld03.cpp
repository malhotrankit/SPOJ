#include<stdio.h>
#include<math.h>
long long lazy[4000005],tree[4000005],l,r,diff,ans;
 
void update(long long si,long long ei,long long index)
{
    if(lazy[index]!=0)
    {    
        tree[index]+=(ei-si+1)*lazy[index];
        if(si!=ei)
        {
            lazy[index*2]+=lazy[index];                  
            lazy[index*2+1]+=lazy[index];                
        }
        lazy[index]=0;                                  
    }
    if(si>r||ei<l)              
        return;
    if(si>=l&&ei<=r)
    {
        tree[index]+=(ei-si+1)*diff;
        if(si!=ei)
        {
            lazy[index*2]+=diff;
            lazy[index*2+1]+=diff;
        }
        return;
    }
    update(si,(si+ei)/2,index*2);
    update((si+ei)/2+1,ei,index*2+1);
    tree[index]=tree[index*2]+tree[index*2+1];
}
 
void query(long long si,long long ei,long long index)
{
    if(si>r||ei<l)
        return;
    if(lazy[index]!=0)
    {    
        tree[index]+=(ei-si+1)*lazy[index];
        if(si!=ei)
        {
            lazy[index*2]+=lazy[index];                  
            lazy[index*2+1]+=lazy[index];                
        }
        lazy[index]=0;
    }
    if(si>=l&&ei<=r)
    {
        ans=ans+tree[index];
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
 
int main() 
{
    char str[6];
    long long n,i,ht,size,q;
    scanf("%lld%lld",&n,&q);
    ht=(long long)ceil(log(n)/log(2));
    size=2*(long long)pow(2,ht)-1;
    for(i=1;i<=q;i++)
    {
        scanf("%s",&str);
        scanf("%lld%lld",&l,&r);
        if(str[0]=='a')
        {
            diff=r;
            r=l;
            update(1,n,1);
        }
        else if(str[0]=='f')
        {
            ans=0;
            query(1,n,1);
            printf("%lld\n",ans);
        }
    }
    return 0;
} 