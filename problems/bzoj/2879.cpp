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
//type19

const int N=45, M=105, nN=N+M+1000, nE=N*(M+800)*8, oo=0x3f3f3f3f;
int ihead[nN], cnt=1;
struct E {
	int next, from, to, cap, w;
}e[nE];
void add(int x, int y, int cap, int w) {
	e[++cnt]=(E){ihead[x], x, y, cap, w}; ihead[x]=cnt;
	e[++cnt]=(E){ihead[y], y, x, 0,  -w}; ihead[y]=cnt;
}
bool spfa(int s, int t, int n, int &ans) {
	static int d[nN], q[nN], p[nN], fr, ta;
	static bool vis[nN];
	memset(d, 0x3f, sizeof(int)*(n+1));
	fr=ta=0;
	d[s]=0;
	q[ta++]=s;
	while(fr!=ta) {
		int x=q[fr++];
		fr=fr==nN?0:fr;
		vis[x]=0;
		for(int i=ihead[x]; i; i=e[i].next) {
			if(!e[i].cap) {
				continue;
			}
			int y=e[i].to;
			if(d[y]>d[x]+e[i].w) {
				d[y]=d[x]+e[i].w;
				p[y]=i;
				if(!vis[y]) {
					vis[y]=1;
					q[ta++]=y;
					ta=ta==nN?0:ta;
				}
			}
		}
	}
	if(d[t]==oo) {
		return 0;
	}
	for(int x=t; x!=s; x=e[p[x]].from) e[p[x]].cap--, e[p[x]^1].cap++;
	ans+=d[t];
	return 1;
}
int n, m, p[N], sum, pos[M], num[M], t[N][M], nu[N];
int main() {
	int ans=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) {
		scanf("%d", &p[i]);
		sum+=p[i];
	}
	int S=n+m+sum+1, T=S+1;
	for(int i=1; i<=n; ++i) {
		add(S, i, p[i], 0);
		for(int j=1; j<=m; ++j) {
			scanf("%d", &t[i][j]);
		}
	}
	for(int j=1; j<=m; ++j) {
		int id=n+j;
		add(id, T, 1, 0);
		num[j]=1;
		pos[j]=cnt;
		for(int i=1; i<=n; ++i) {
			add(i, id, 1, t[i][j]);
		}
	}
	int tot=n+m;
	while(spfa(S, T, T, ans)) {
		int j=0;
		for(j=1; j<=m && !e[pos[j]].cap; ++j);
		++num[j];
		++tot;
		add(tot, T, 1, 0);
		pos[j]=cnt;
		for(int i=1; i<=n; ++i) {
			add(i, tot, 1, num[j]*t[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
