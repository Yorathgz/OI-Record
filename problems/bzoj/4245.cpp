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

int main() {
	int n=getint(), m=getint();
	for(int i=1; i<=n; ++i) {
		a[i]=getint();
		a[i]^=a[i-1];
	}
	ll ans=0;
	for(int j=63; ~j; --j) {
		if((a[n]>>j)&1) {
			ans|=1ll<<j;
			continue;
		}
		int cnt=0;
		for(int i=1; i<=n; ++i) {
			if(a[i]>=0 && !((a[i]>>j)&1)) {
				++cnt;
			}
		}
		if(cnt>=m) {
			for(int i=1; i<=n; ++i) {
				if(a[i]>=0 && ((a[i]>>j)&1)) {
					a[i]=-a[i];
				}
			}
		}
		else {
			ans|=1ll<<j;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
