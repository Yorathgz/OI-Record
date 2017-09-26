#include<cstdio>
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
struct edge{int v,p;}e[maxn<<1];
int n,tot,last[maxn],ans;
bool mark[maxn];
inline void insert(int u,int v){e[++tot]=(edge){v,last[u]};last[u]=tot;}
inline void ins(int a,int b){insert(a,b);insert(b,a);}

int dfs(int x,int fa){
	bool flag=0;
	for(int i=last[x];i;i=e[i].p){
		if(e[i].v==fa) continue;
		dfs(e[i].v,x);
		if(mark[e[i].v]) flag=1;
	}
	if(!flag&&!mark[x]&&!mark[fa])
		mark[fa]=1,ans++;
}

int main(){
	n=read();
	for(int i=1,t;i<n;i++) t=read(),ins(t,read());
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
