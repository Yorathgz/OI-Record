#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define ll long long
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
//type17,


ll read()
{
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

int n,m,cnt,cir,tot;
int last[50005];
ll bin[65],v[250005],d[50005];
bool vis[50005];

struct{
	int to,next;ll v;
}e[200005];

void insert(int u,int v,ll w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to])
		{
			d[e[i].to]=d[x]^e[i].v;
			dfs(e[i].to);
		}
		else v[++cir]=d[x]^d[e[i].to]^e[i].v;
}

void gauss()
{
	for(ll i=bin[60];i;i>>=1)
	{
		int j=tot+1;
		while(j<=cir&&!(v[j]&i))j++;
		if(j==cir+1)continue;
		tot++;
		swap(v[tot],v[j]);
		for(int k=1;k<=cir;k++)
			if(k!=tot&&(v[k]&i))
				v[k]^=v[tot];
	}
}

int main()
{
	bin[0]=1;for(int i=1;i<=60;i++)bin[i]=bin[i-1]<<1;
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ll w=read();
		insert(u,v,w);
	}
	dfs(1);gauss();
	ll ans=d[n];
	for(int i=1;i<=tot;i++)
		ans=max(ans,ans^v[i]);
	printf("%lld",ans);
	return 0;
}
