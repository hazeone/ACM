#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int l,r,w,where,num,father;
}t[200000];
int n,m,rev[200000],len;
struct bian{
    int point1,point2,a,b;
}b[110000];
int operator < (const bian k1,const bian k2){
    return k1.a<k2.a;
}
void change(int k){
    if (k==0) return;
    if (t[t[k].l].num>t[t[k].r].num){
        t[k].where=t[t[k].l].where; t[k].num=t[t[k].l].num;
    } else {t[k].where=t[t[k].r].where; t[k].num=t[t[k].r].num;}
    if (t[k].w>t[k].num){t[k].num=t[k].w; t[k].where=k;}
}
void reverse(int k){
    if (k==0) return; rev[k]^=1; swap(t[k].l,t[k].r);
}
void pushdown(int k){
    if (rev[k]){
        reverse(t[k].l); reverse(t[k].r); rev[k]=0;
    }
}
void zig(int k){
    int f=t[k].father; pushdown(f); pushdown(k);
    if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
    t[k].father=t[f].father; t[f].l=t[k].r; t[t[f].l].father=f; t[k].r=f; t[f].father=k; change(f);
}
void zag(int k){
    int f=t[k].father; pushdown(f); pushdown(k);
    if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
    t[k].father=t[f].father; t[f].r=t[k].l; t[t[f].r].father=f; t[k].l=f; t[f].father=k; change(f);
}
int splay_root(int k){
    return t[k].father&&(t[t[k].father].l==k||t[t[k].father].r==k);
}
void splay(int k){
    pushdown(k); while (splay_root(k)) if (t[t[k].father].l==k) zig(k); else zag(k); change(k);
}
int access(int k){
    int now=0;
    while (k){
        splay(k); t[k].r=now; change(k); now=k; k=t[k].father;
    }
    return now;
}
void makeroot(int k){
    reverse(access(k)); splay(k);
}
int findfather(int k){
    while (t[k].father) k=t[k].father; return k;
}
int find(int k1,int k2){
    makeroot(k1); if (findfather(k2)==k1) return t[access(k2)].num; else return 1e9;
}
void link(int k1,int k2){
    makeroot(k1); t[k1].father=k2; int k3=access(k1); 
}
void cut(int k1,int k2){
    makeroot(k1); int k3=access(k2); splay(k2); t[k2].l=0; t[k1].father=0; change(k2);
}
void del(int k){
    cut(k,b[k-n].point1); cut(k,b[k-n].point2);
}
void insert(int k1,int k2,int k3){
    len++; t[len].w=k3; t[len].num=k3; t[len].where=len;
    if (k1==k2) return;
    makeroot(k1); if (findfather(k2)!=k1){link(len,k1); link(len,k2); return;} int k4=access(k2);
    if (t[k4].num>k3){del(t[k4].where); link(len,k1); link(len,k2);}
}
int main(){
    scanf("%d%d",&n,&m); len=n;
    for (int i=1;i<=m;i++) scanf("%d%d%d%d",&b[i].point1,&b[i].point2,&b[i].a,&b[i].b); sort(b+1,b+m+1);
    memset(t,0x00,sizeof t); int ans=1e9;
    for (int i=1;i<=m;i++){
        insert(b[i].point1,b[i].point2,b[i].b); int k1=find(1,n);
        ans=min(ans,b[i].a+k1);
    }
    if (ans==1e9) cout<<-1<<endl; else cout<<ans<<endl;
    return 0;
}
