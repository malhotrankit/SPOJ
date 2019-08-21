#include<stdio.h>
#include<math.h>
long long *tree,ans,*lazy,l,r,diff;
void update(long long si,long long ei,long long index)
{
    if(lazy[index] != 0)
    { 
        tree[index]+=(ei-si+1)*lazy[index];    
        if(si!=ei)
        {
            lazy[index*2]+=lazy[index];                  
            lazy[index*2+1]+=lazy[index];                
        }
        lazy[index]=0;                                  
    }
    if(si>ei||si>r||ei<l)              
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
    tree[index] = tree[index*2] + tree[index*2+1]; 
}
void query(long long si,long long ei,long long index)
{
    if(si>ei||si>r||ei<l)
        return;
    if(lazy[index]!=0)
    {
        tree[index]+=(ei-si+1)*lazy[index];
        if(si!=ei)
        {
            lazy[index*2]+=lazy[index];      
            lazy[index*2+1]+=lazy[index];
        }
        lazy[index] = 0;
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
        printf("%lld ",tree[i]);
    printf("\n");
}*/
int main(void) 
{
    long long n,i,ht,size,q,t,p;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        ht=(long long)ceil(log(n)/log(2));
        size=2*(long long)pow(2,ht)-1;
        tree=new long long[size+1];
        lazy=new long long[size+1];
        //display(size);
        for(i=1;i<=q;i++)
        {
            scanf("%lld%lld%lld",&p,&l,&r);
            if(p==0)
            {
                scanf("%lld",&diff);
                update(1,n,1);
                //display(size);
            }
            else
            {
                ans=0;
                query(1,n,1);
                printf("%lld\n",ans);
            }
        }
        delete tree;
        delete lazy;
    }
    return 0;
} 