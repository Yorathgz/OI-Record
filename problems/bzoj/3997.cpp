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

typedef long long ll;
ll d[1005][1005];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				scanf("%lld", &d[i][j]);
			}
		}
		for(int i=1; i<=n; ++i) {
			for(int j=m; j>=1; --j) {
				d[i][j]=max(d[i][j]+d[i-1][j+1], max(d[i][j+1], d[i-1][j]));
			}
		}
		printf("%lld\n", d[n][1]);
	}
	return 0;
}
