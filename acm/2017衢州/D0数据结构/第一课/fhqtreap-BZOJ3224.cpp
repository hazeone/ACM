#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int l,r,size,w,f;
}t[110000];
int n,len,root;
int getrank(){
    return (rand()<<16)+rand();
}
void change(int k){
    if (k==0) return;
    t[k].size=t[t[k].l].size+t[t[k].r].size+1;
}
int merge(int k1,int k2){
    if (k1==0||k2==0) return k1+k2;
    if (t[k1].f>t[k2].f){
        t[k1].r=merge(t[k1].r,k2); change(k1); return k1;
    } else {t[k2].l=merge(k1,t[k2].l); change(k2); return k2;}
}
void splite(int k1,int k2,int &k3,int &k4){
    if (k1==0){k3=0; k4=0; return;}
    if (t[k1].w<k2){
        k3=k1; splite(t[k1].r,k2,t[k1].r,k4);
    } else {k4=k1; splite(t[k1].l,k2,k3,t[k1].l);}
    change(k1);
}
int insert(int k1,int k2){
    if (k1==0) return k2;
    if (t[k1].f>t[k2].f){
        if (t[k1].w<t[k2].w) t[k1].r=insert(t[k1].r,k2); else t[k1].l=insert(t[k1].l,k2);
        change(k1); return k1;
    };
    splite(k1,t[k2].w,t[k2].l,t[k2].r); change(k2); return k2;
}
int find(int k1,int k2){
    if (t[t[k1].l].size==k2-1) return t[k1].w;
    if (t[t[k1].l].size>=k2) return find(t[k1].l,k2);
    return find(t[k1].r,k2-t[t[k1].l].size-1);
}
int findleft(int k){
    while (t[k].l) k=t[k].l; return t[k].w;
}
int findright(int k){
    while (t[k].r) k=t[k].r; return t[k].w;
}
int main(){
    srand(1342);
    scanf("%d",&n); len=0; root=0;
    memset(t,0x00,sizeof t);
    for (;n;n--){
        int k1,k2; scanf("%d",&k1);
        if (k1==1){
            scanf("%d",&k2); len++; t[len].f=getrank(); t[len].w=k2; t[len].size=1; root=insert(root,len);
        } else if (k1==2){
            scanf("%d",&k2); int k3,k4,k5; splite(root,k2,k3,k4); splite(k4,k2+1,k4,k5); root=merge(merge(k3,t[k4].l),merge(t[k4].r,k5));
        } else if (k1==3){
            scanf("%d",&k2); int k3,k4; splite(root,k2,k3,k4); printf("%d\n",t[k3].size+1); root=merge(k3,k4);
        } else if (k1==4){
            scanf("%d",&k2); printf("%d\n",find(root,k2));
        } else if (k1==5){
            scanf("%d",&k2); int k3,k4; splite(root,k2,k3,k4); printf("%d\n",findright(k3)); root=merge(k3,k4);
        } else {
            scanf("%d",&k2); int k3,k4; splite(root,k2+1,k3,k4); printf("%d\n",findleft(k4)); root=merge(k3,k4);
        }
    }
    return 0;
}
