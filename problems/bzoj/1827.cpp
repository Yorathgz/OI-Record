#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=1e5+5;
struct edge{int v,w,p;}e[maxn<<1];
int n,c[maxn],tot,last[maxn];
ll ans,dis[maxn],size[maxn];
inline void insert(int u,int v,int w){e[++tot]=(edge){v,w,last[u]};last[u]=tot;}

ll build(int x,int fa){
	ll tmp=dis[x]*c[x];
	size[x]=c[x];
	for(int i=last[x],v;i;i=e[i].p){
		v=e[i].v;
		if(v==fa) continue;
		dis[v]=dis[x]+e[i].w;
		tmp+=build(v,x);
		size[x]+=size[v];
	}
	return tmp;
}

void move(int x,int fa){
	for(int i=last[x],v;i;i=e[i].p){
		v=e[i].v;
		if(v==fa) continue;
		if(size[1]-2*size[v]<0){
			ans=ans+(size[1]-2*size[v])*e[i].w;
			move(v,x);
		}
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1,a,b,l;i<n;i++)
		a=read(),b=read(),l=read(),
		insert(a,b,l),insert(b,a,l);
	ans=build(1,0);
	move(1,0);
	cout<<ans<<endl;
	return 0;
}
