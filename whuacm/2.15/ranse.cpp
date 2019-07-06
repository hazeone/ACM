#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int N=100005;
int n,m;
int a[N];
char c[4];
struct point
{
	int to,next;
}e[N*2];
struct node
{
	int lazy,lc,rc,sum;
}t[8*N];
int g[N],tot;
int dep[N],sz[N],id[N],ls[N],h[N],cnt,rid[N],fa[N],cntl=1;
void dfs1(int now,int f)
{
	sz[now]=1;
	fa[now]=f;
	dep[now]=dep[f]+1;
	for(int tmp=g[now];tmp;tmp=e[tmp].next)
	{
		if(e[tmp].to==f)continue;
		dfs1(e[tmp].to,now);
		sz[now]+=sz[e[tmp].to];
	}
}
void dfs2(int now,int pre)
{
	id[now]=++cnt;
	rid[cnt]=now;
	ls[cnt]=cntl;
	h[cnt]=pre;
	int we,mx=-1;
	for(int tmp=g[now];tmp;tmp=e[tmp].next)
	{
		if(!id[e[tmp].to])
		{
			if(sz[e[tmp].to]>mx)
			{
				mx=sz[e[tmp].to];
				we=e[tmp].to;
			}
		}
	}
	if(mx>0)
	{
		dfs2(we,pre);
	}
	for(int tmp=g[now];tmp;tmp=e[tmp].next)
	{
		if(!id[e[tmp].to])
		{
			cntl++;
			dfs2(e[tmp].to,cnt+1);
		}
	}
}
void add(int x,int y)
{
	
	e[++tot].to=y;
	e[tot].next=g[x];
	g[x]=tot;
}
void down(int o)
{
	t[o*2].lazy=t[o*2+1].lazy=t[o].lc=t[o].rc=t[o].lazy;
	t[o].sum=1;
	t[o].lazy=-1;
}
void up(int o)
{
	if(t[o*2].lazy)down(o*2);
	if(t[o*2+1].lazy)down(o*2+1);
	t[o].lc=t[o*2].lc;
	t[o].rc=t[o*2+1].rc;
	t[o].sum=t[o*2].sum+t[o*2+1].sum-(t[o*2].rc==t[o*2+1].lc);
	t[o].lazy=-1;
}
void build(int l,int r,int o)
{
	//if(o==11)cout<<"???"<<endl;
	if(l==r)
	{
		t[o].lazy=-1;
		t[o].lc=t[o].rc=a[rid[l]];
		t[o].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,o*2);
	build(mid+1,r,o*2+1);
	up(o);
}
int qsum(int l,int r,int L,int R,int o)
{
	if(L==R)
	{
		if(t[o].lazy>=0)
		{
			t[o].rc=t[o].lc=t[o].lazy;
			t[o].lazy=-1;
			t[o].sum=1;
		}
		return 1;
	}
	if(t[o].lazy>=0)
	{
		down(o);
		return 1;
	}
	if(l==L&&r==R)
	return t[o].sum;
	int mid=(L+R)/2;
	if(mid>=r)
	return qsum(l,r,L,mid,o*2);
	else if(mid<l)
	return qsum(l,r,mid+1,R,o*2+1);
	else
	{
		return qsum(l,mid,L,mid,o*2)+qsum(mid+1,r,mid+1,R,o*2+1)-(t[o*2].rc==t[o*2+1].lc);//
	}
}
int qc(int x,int l,int r,int o)
{
	if(l==r)
	{
		if(t[o].lazy>=0)
		{
			t[o].lc=t[o].rc=t[o].lazy;
			t[o].lazy=-1;
			t[o].sum=1;
		}
		return t[o].rc;
	}
	if(t[o].lazy>=0)
	{
		return t[o].lazy;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	return qc(x,l,mid,o*2);
	else return qc(x,mid+1,r,o*2+1);
}
void query(int x,int y)
{
	int ans=0;
	while(ls[x]!=ls[y])
	{//cout<<"!!!!"<<endl;
		if(dep[rid[x]]<dep[rid[y]])swap(x,y);
		ans=ans+qsum(h[x],x,1,n,1)-(qc(h[x],1,n,1)==qc(id[fa[rid[h[x]]]],1,n,1));
		x=id[fa[rid[h[x]]]];
	}
	if(x>y)swap(x,y);
	//cout<<x<<y<<endl;
	ans+=qsum(x,y,1,n,1);
	printf("%d\n",ans);
}
void ad(int l,int r,int L,int R,int o,int z)
{
	if(L==R)
	{
		t[o].rc=t[o].lc=z;
		t[o].lazy=-1;
		t[o].sum=1;return;
	}
	if(l==L&&r==R)
	{
		t[o].lazy=z;
		down(o);
		return ;
	}
	if(t[o].lazy>=0)down(o);
	int mid=(L+R)/2;
	if(l>mid)
	{
		ad(l,r,mid+1,R,o*2+1,z);
	}
	else if(r<=mid)ad(l,r,L,mid,o*2,z);
	else
	{
		ad(l,mid,L,mid,o*2,z);
		ad(mid+1,r,mid+1,R,o*2+1,z);
	}
	up(o);
}
void change(int x,int y,int z)
{
	while(ls[x]!=ls[y])
	{//cout<<"!!!!!!"<<endl;
		if(dep[rid[x]]<dep[rid[y]])swap(x,y);
		ad(h[x],x,1,n,1,z);
		x=id[fa[rid[h[x]]]];
	}
	if(x>y)swap(x,y);
	//cout<<x<<y<<endl;
	ad(x,y,1,n,1,z);
	for(int i=1;i<=13;i++)
	cout<<t[i].sum<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].lazy<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].lc<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].rc<<" ";cout<<endl;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,n,1);
	for(int i=1;i<=13;i++)
	cout<<t[i].sum<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].lazy<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].lc<<" ";cout<<endl;
	for(int i=1;i<=13;i++)
	cout<<t[i].rc<<" ";cout<<endl;
	/*cout<<"sz: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<sz[i]<<" ";
	}cout<<endl;
	cout<<"id: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<id[i]<<" ";
	}cout<<endl;
	cout<<"ls: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<ls[i]<<" ";
	}cout<<endl;
	cout<<"h: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<h[i]<<" ";
	}cout<<endl;
	cout<<"rid: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<rid[i]<<" ";
	}cout<<endl;
	cout<<"fa: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<fa[i]<<" ";
	}cout<<endl;*/
	for(int i=1;i<=m;i++)
	{
		cin>>c;
		int x,y,z;
		if(c[0]=='Q')
		{
			scanf("%d%d",&x,&y);
			query(id[x],id[y]);
		}
		else
		{
			scanf("%d%d%d",&x,&y,&z);
			change(id[x],id[y],z);
		}
	}
	return 0;
}
