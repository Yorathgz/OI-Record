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

const int N=605, vN=N*N+N, oo=~0u>>1;
int ihead[vN], cnt=1;
struct E {
	int next, to, cap;
}e[6*N*N+2*N];
inline void add(int x, int y, int cap) {
	e[++cnt]=(E){ihead[x], y, cap}; ihead[x]=cnt;
	e[++cnt]=(E){ihead[y], x, cap}; ihead[y]=cnt;
}
inline int min(const int &a, const int &b) {
	return a<b?a:b;
}
int isap(int s, int t, int n) {
	static int gap[vN], cur[vN], d[vN], p[vN];
	gap[0]=n;
	int r=0, x=s, i, f;
	for(; d[s]<n;) {
		for(i=cur[x]; i && !(e[i].cap && d[x]==d[e[i].to]+1); i=e[i].next);
		if(i) {
			p[e[i].to]=cur[x]=i;
			if((x=e[i].to)==t) {
				for(f=oo, x=t; x!=s; f=min(f, e[p[x]].cap), x=e[p[x]^1].to);
				for(r+=f, x=t; x!=s; e[p[x]].cap-=f, e[p[x]^1].cap+=f, x=e[p[x]^1].to);
			}
		}
		else {
			if(!--gap[d[x]]) break;
			d[x]=n;
			for(i=ihead[x]; i; i=e[i].next) {
				if(e[i].cap && d[x]>d[e[i].to]+1) {
					d[x]=d[e[i].to]+1;
					cur[x]=i;
				}
			}
			++gap[d[x]];
			if(x!=s) x=e[p[x]^1].to;
		}
	}
	return r;
}
int main() {
	int n=getint(), sum=0, S, T;
	S=n*(n+1)+1, T=S+1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			int id=i*n+j, w=getint();
			add(id, T, w);
			if(i!=j) add(i, id, oo);
			add(j, id, oo);
			sum+=w;
		}
	}
	for(int i=1; i<=n; ++i) {
		add(S, i, getint());
	}
	printf("%d\n", sum-isap(S, T, T));
	return 0;
}
