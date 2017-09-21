#include<cstdio>
#include<cstring>
#include<deque>
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

const int maxn=25005;
const int maxm=1e5+5;
const int inf=0x3f3f3f3f;
struct edge{int v,w,p;}e[maxm<<1];
int t,r,p,s,tot,last[maxn],dis[maxn],vis[maxn];
inline void insert(int u,int v,int w){e[++tot]=(edge){v,w,last[u]};last[u]=tot;}

inline void spfa(int x){
	deque<int> q;
	clr(dis,0x3f);
	q.push_back(x);dis[x]=0;vis[x]=1;
	int u,v;
	while(!q.empty()){
		u=q.front();q.pop_front();vis[u]=0;
		for(int i=last[u];i;i=e[i].p){
			v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]){
					vis[v]=1;
					if(q.empty()||dis[v]>dis[q.front()]) q.push_back(v);
					else q.push_front(v);
				}
			}
		}
	}
}

int main(){
	t=read();r=read();p=read();s=read();
	for(int i=1,a,b,c;i<=r;i++)
		a=read(),b=read(),c=read(),
		insert(a,b,c),insert(b,a,c);
	for(int i=1,a,b,c;i<=p;i++)
		a=read(),b=read(),c=read(),
		insert(a,b,c);
	spfa(s);
	for(int i=1;i<=t;i++){
		if(dis[i]<inf) printf("%d\n",dis[i]);
		else printf("NO PATH\n");
	}
	return 0;
}
