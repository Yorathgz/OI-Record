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

const int mo=19940417;
ll cal(int n, ll a) {
	ll ret=a%mo*n%mo, tp=0;
	for(int i=1, pos=0; i<=n; i=pos+1) {
		pos=n/(n/i);
		tp+=(a/i)%mo*(((ll)(pos+1)*pos/2-(ll)(i-1)*i/2)%mo)%mo;
		if(tp>=mo) {
			tp-=mo;
		}
	}
	return (ret-tp+mo)%mo;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if(n>m) {
		swap(n, m);
	}
	printf("%lld\n", (cal(n, n)*cal(m, m)%mo-cal(n, (ll)n*m)+mo)%mo);
	return 0;
}
