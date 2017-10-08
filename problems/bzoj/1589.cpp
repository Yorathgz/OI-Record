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
inline void write(ll x){
	if(x<0) x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int maxn=1e5+5;
int n,nxt[maxn],clnxt[maxn],ans[maxn],sum[maxn];
int dfn[maxn],low[maxn],stk[maxn],col[maxn],clcnt,dfcnt,top;
bool ins[maxn];

inline void tarjan(int u){
	dfn[u]=low[u]=++dfcnt;
	ins[u]=1;stk[++top]=u;
	int v=nxt[u];
	if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
	else if(ins[v]) low[u]=min(low[u],dfn[v]);
	int t;
	if(dfn[u]==low[u]){
		clcnt++;do{
			t=stk[top--];
			ins[t]=0;
			col[t]=clcnt;
			sum[clcnt]++;
		}while(t!=u);
	}
}

inline void getans(int u){
	ans[u]=sum[u];
	int v=clnxt[u];
	if(!v) return;
	if(!ans[v]) getans(v);
	if(sum[u]==1) ans[u]+=ans[v];
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)
		nxt[i]=read();
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
		if(col[nxt[i]]!=col[i]){
			clnxt[col[i]]=col[nxt[i]];
			continue;
		}
	for(int i=1;i<=n;i++){
		if(!ans[col[i]]) getans(col[i]);
		write(ans[col[i]]),putchar('\n');
	}
	return 0;
}
