#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define LL long long
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=0;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

/*************************************************************/
//type19, 

	template <class classname>
inline void in(classname &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
unordered_map<int,int> Hash;
int n,m,S,T,top,ans;
bool vis[MAXN];
int dis[MAXN],cnt[MAXN],tmp[MAXN];
int C[MAXN][MAXN],num[MAXN],mncut[MAXN][MAXN];
struct edge {   int st,to,c;    edge *next,*rev;    }e[MAXN*10<<1],*prev[MAXN];
inline void insert(int u,int v,int c)   {   e[++top].to=v;e[top].st=u;e[top].c=c;e[top].next=prev[u];prev[u]=&e[top];   }
inline void add(int u,int v,int c)  {   insert(u,v,c);insert(v,u,c);prev[u]->rev=prev[v];prev[v]->rev=prev[u];  }
int ISAP()
{
	edge *E[MAXN],*rep[MAXN];int ret=0;int now=S;
	for (int i=1;i<=n;++i)  E[i]=prev[i];
	memset(dis,0,sizeof(dis));memset(cnt,0,sizeof(cnt));cnt[0]=n;
	while (dis[S]<=n)
	{
		edge *i;bool flag=0;
		for (i=E[now];i;i=i->next)  if (i->c>0&&dis[i->to]+1==dis[now]) {   flag=1;E[now]=i;break;  }
		if (flag)
		{
			rep[now=i->to]=i;
			if (now==T)
			{
				int minn=0x3f3f3f3f;
				for (int i=T;i!=S;i=rep[i]->st) minn=min(minn,rep[i]->c);
				for (int i=T;i!=S;i=rep[i]->st) rep[i]->c-=minn,rep[i]->rev->c+=minn;
				ret+=minn;now=S;
			}
			continue;
		}
		if (!(--cnt[dis[now]])) break;
		int mind=n+1;E[now]=prev[now];
		for (edge *i=prev[now];i;i=i->next) if (i->c>0) mind=min(mind,dis[i->to]);
		dis[now]=mind+1;++cnt[dis[now]];
		if (now!=S) now=rep[now]->st;
	}
	return ret;
}
void dfs(int x)
{
	vis[x]=1;
	for (edge *i=prev[x];i;i=i->next)   if (i->c>0&&!vis[i->to])    dfs(i->to);
}
void solve(int l,int r)
{
	if (l==r)   return;
	for (int i=1;i<=top;i+=2)   e[i].c=e[i].rev->c=((e[i].c+e[i].rev->c)>>1);
	S=num[l];T=num[r];int t=ISAP();memset(vis,0,sizeof(vis));dfs(S);
	for (int i=1;i<=n;i++)
		if (vis[i])
			for (int j=1;j<=n;j++)
				if (!vis[j])    mncut[i][j]=min(mncut[i][j],t),mncut[j][i]=min(mncut[j][i],t);
	int tp=0,len,L=l-1;
	for (int i=l;i<=r;i++)  if (vis[num[i]])    tmp[++tp]=num[i];len=tp;
	for (int i=l;i<=r;i++)  if (!vis[num[i]])   tmp[++tp]=num[i];
	for (int i=1;i<=tp;i++) num[++L]=tmp[i];
	solve(l,l+len-1);solve(l+len,r);
}
int main()
{
	in(n);in(m);int u,v,w;memset(mncut,0x3f,sizeof(mncut));
	for (int i=1;i<=n;i++)  num[i]=i;
	for (int i=1;i<=m;i++)  in(u),in(v),in(w),C[u][v]+=w,C[v][u]+=w;
	for (int i=1;i<=n;i++)  for (int j=i+1;j<=n;j++)    if (C[i][j])    add(i,j,C[i][j]);
	solve(1,n);
	for (int i=1;i<=n;i++)  for (int j=i+1;j<=n;j++)    if (Hash.find(mncut[i][j])==Hash.end()) {   Hash[mncut[i][j]]=1;ans++;  }
	printf("%d\n",ans);
}
