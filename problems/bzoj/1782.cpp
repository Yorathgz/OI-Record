#include<cstdio>
#define lowbit(x) x&(-x)
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
struct edge{int v,p;}e[maxn<<1];
int n,tot,last[maxn],p[maxn],t[maxn],ans[maxn];
inline void insert(int u,int v){e[++tot]=(edge){v,last[u]};last[u]=tot;}
inline void ins(int a,int b){insert(a,b);insert(b,a);}

inline int ask(int x){
	int sum=0;
	for(int i=x;i;i-=lowbit(i))
		sum+=t[i];
	return sum;
}

inline void update(int x,int val){
	for(int i=x;i<=n;i+=lowbit(i))
		t[i]+=val;
}

void dfs(int x,int fa){
	ans[p[x]]=ask(p[x]);update(p[x],1);
	for(int i=last[x],v;i;i=e[i].p){
		v=e[i].v;
		if(v==fa) continue;
		dfs(v,x);
	}
	update(p[x],-1);
}

int main(){
	n=read();
	for(int i=1,a,b;i<n;i++) a=read(),b=read(),ins(a,b);
	for(int i=1;i<=n;i++) p[read()]=i;
	dfs(1,0);
	for(int i=1;i<=n;i++) write(ans[i]),putchar('\n');
	return 0;
}
