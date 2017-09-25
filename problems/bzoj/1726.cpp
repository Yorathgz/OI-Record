#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=0;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxr=1e5+5;
const int maxn=5e3+5;
const int inf=0x3f3f3f3f;
struct edge{
	int u,v,w,p;
}e[maxr<<1];
int tot,last[maxn];
int n,r;
ll dis[2][maxn];
bool vis[maxn];

inline void insert(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].p=last[u];
	last[u]=tot;
}

inline void init(){
	n=read();r=read();
	for(int i=1,a,b,c;i<=r;i++)
		a=read(),b=read(),c=read(),
		insert(a,b,c),insert(b,a,c);
}

inline void spfa(bool f){
	queue<int> q;
	if(f)dis[f][1]=0,q.push(1),vis[1]=1;
	else dis[f][n]=0,q.push(n),vis[n]=1;
	int u;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(int i=last[u],v;i;i=e[i].p){
			v=e[i].v;
			if(dis[f][v]>dis[f][u]+e[i].w){
				dis[f][v]=dis[f][u]+e[i].w;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
}

int main(){
	memset(dis,inf,sizeof(dis));
	init();
	spfa(0);spfa(1);
	ll ans=inf;
	for(int i=1,u,v,w;i<=tot;i++){
		u=e[i].u;v=e[i].v;
		w=dis[0][u]+dis[1][v]+e[i].w;
		if(w>dis[0][1]&&w<ans)
			ans=w;
	}
	cout<<ans<<endl;
	return 0;
}
