#include <bits/stdc++.h>
#define ll long long
#define inf (1e9+7)
#define N 100086
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct d1{int fw,sw,num,anr;};//fw mim/max   sw cixiaozhi  num geshu anr lingyiwei
struct dt{d1 up,down,left,right;}f[N*4];
int x[N],y[N];

d1 mergemin(d1 t1,d1 t2)
{
    d1 t;
    if(t1.fw==t2.fw)
    {
        t=t1;t.num=t1.num+t2.num;
        t.sw=min(t1.sw,t2.sw);
    }
    if(t1.fw<t2.fw)
    {
        t=t1;t.sw=min(t1.sw,t2.fw);
    }
    if(t1.fw>t2.fw)
    {
        t=t2;t.sw=min(t2.sw,t1.fw);
    }
    return t;
}
d1 mergemax(d1 t1,d1 t2)
{
    d1 t;
    if(t1.fw==t2.fw)
    {
        t=t1;t.num=t1.num+t2.num;
        t.sw=max(t1.sw,t2.sw);
    }
    if(t1.fw>t2.fw)
    {
        t=t1;t.sw=max(t1.sw,t2.fw);
    }
    if(t1.fw<t2.fw)
    {
        t=t2;t.sw=max(t2.sw,t1.fw);
    }
    return t;
}
dt merge(dt t1,dt t2)
{
    dt t;
    t.up=mergemin(t1.up,t2.up);
    t.left=mergemin(t1.left,t2.left);
    t.down=mergemax(t1.down,t2.down);
    t.right=mergemax(t1.right,t2.right);
    return t;
}
void build(int i,int l,int r)
{
    if(l==r)
    {
        f[i].up.fw=x[l];f[i].up.sw=inf;f[i].up.num=1;f[i].up.anr=y[l];
        f[i].down.fw=x[l];f[i].down.sw=-inf;f[i].down.num=1;f[i].down.anr=y[l];
        f[i].left.fw=y[l];f[i].left.sw=inf;f[i].left.num=1;f[i].left.anr=x[l];
        f[i].right.fw=y[l];f[i].right.sw=-inf;f[i].right.num=1;f[i].right.anr=x[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);build(i*2+1,mid+1,r);
    f[i]=merge(f[i*2],f[i*2+1]);
}
dt ask(int i,int l,int r,int lt,int rt)
{
    if(lt<=l&&r<=rt)return f[i];
    int mid=(l+r)/2;
    dt res;
    if(lt<=mid&&rt<=mid)res=ask(i*2,l,mid,lt,rt);
    if(mid+1<=rt&&mid+1<=lt)res=ask(i*2+1,mid+1,r,lt,rt);
    if(lt<=mid&&mid+1<=rt)res=merge(ask(i*2,l,mid,lt,rt),ask(i*2+1,mid+1,r,lt,rt));
    return res;
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int l=read(),r=read();
        if(r-l+1<=2){puts("0");continue;}
        dt t=ask(1,1,n,l,r);
        //if(l==r){puts("0");continue;}
        int ans=min(t.down.fw-t.up.fw,t.right.fw-t.left.fw);
        cout<<ans<<" ";
        if(t.up.num==1)
        {
            int h=t.down.fw-t.up.sw;
            int s=t.right.fw-t.left.fw;
            if(t.right.fw==t.up.anr&&t.right.num==1)s=t.right.sw-t.left.fw;
            if(t.left.fw==t.up.anr&&t.left.num==1)s=t.right.fw-t.left.sw;
            ans=min(ans,min(h,s));
        }
        if(t.down.num==1)
        {
            int h=t.down.sw-t.up.fw;
            int s=t.right.fw-t.left.fw;
            if(t.right.fw==t.down.anr&&t.right.num==1)s=t.right.sw-t.left.fw;
            if(t.left.fw==t.down.anr&&t.left.num==1)s=t.right.fw-t.left.sw;
            ans=min(ans,min(h,s));
        }
        if(t.left.num==1)
        {
            int h=t.down.fw-t.up.fw;
            int s=t.right.fw-t.left.sw;
            if(t.up.fw==t.left.anr&&t.up.num==1)h=t.down.fw-t.up.sw;
            if(t.down.fw==t.left.anr&&t.down.num==1)h=t.down.sw-t.up.fw;
            ans=min(ans,min(h,s));
        }
        if(t.right.num==1)
        {
            int h=t.down.fw-t.up.fw;
            int s=t.right.sw-t.left.fw;
            if(t.up.fw==t.right.anr&&t.up.num==1)h=t.down.fw-t.up.sw;
            if(t.down.fw==t.right.anr&&t.down.num==1)h=t.down.sw-t.up.fw;
            ans=min(ans,min(h,s));
        }
        cout<<ans<<endl;
    }
    return 0;
}
