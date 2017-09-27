#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=505;
const int inf=0x3f3f3f3f;
struct edge{int v,w,p;}e[5500];
int f,n,m,w,tot,last[maxn],dis[maxn],cnt[maxn],count;bool vis[maxn],flag;
inline void insert(int u,int v,int w){e[++tot]=(edge){v,w,last[u]};last[u]=tot;}

inline void bfs_spfa(){//常规spfa 
	queue<int> q;
	clr(dis,0x3f);clr(cnt,0);clr(vis,0);
	dis[1]=0;vis[1]=1;q.push(1);
	int u,v;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(int i=last[u];i;i=e[i].p){
			v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]){
					cnt[v]++;vis[v]=1;q.push(v);
					if(cnt[v]>n){printf("YES\n");return;}
				}
			}
		}
	}
	printf("NO\n");
}

inline void dfs(int u){
	vis[u]=1;
	for(int i=last[u],v;i;i=e[i].p){
		v=e[i].v;
		if(dis[v]>dis[u]+e[i].w){
			if(vis[v]){flag=1;return;}
			dis[v]=dis[u]+e[i].w;
			dfs(v);
		}
	}
	vis[u]=0;
} 

inline void dfs_spfa(){
	flag=0;clr(dis,0);clr(vis,0);
	for(int i=1;i<=n;i++){
		dfs(i);
		if(flag){printf("YES\n");return;}
	}
	printf("NO\n");
}

int main(){
	f=read();
	while(f--){
		tot=0;clr(last,0);
		n=read();m=read();w=read();
		for(int i=1,u,v,t;i<=m;i++)
			u=read(),v=read(),t=read(),
			insert(u,v,t),insert(v,u,t);
		for(int i=1,u,v,t;i<=w;i++)
			u=read(),v=read(),t=read(),
			insert(u,v,-t);
//		bfs_spfa();
		dfs_spfa();
	}
	return 0;
}
