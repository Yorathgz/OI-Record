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

void mul(mtx a, mtx b, mtx c, int la, int lb, int lc) {
	static mtx t;
	memset(t, 0, sizeof t);
	for(int i=0; i<la; ++i) {
		for(int j=0; j<lc; ++j) {
			for(int k=0; k<lb; ++k) {
				CK(t[i][j]+=mul(a[i][k], b[k][j]));
			}
		}
	}
	memcpy(c, t, sizeof t);
}
ll b, d, n;
bool spj(ll n) {
	if(n==1) {
		printf("%lld\n", (ll)((((double)b+sqrt(d))/2.0)));
	}
	else if(n==2) {
		printf("%lld\n", (b*b+d)/2);
	}
	return n<=2;
}
mtx a, c;
int main() {
	scanf("%lld%lld%lld", &b, &d, &n);
	if(spj(n)) {
		return 0;
	}
	ll t1=b, t2=(d-b*b)/4;
	CK(t1), CK(t2);
	a[0][0]=t1, a[0][1]=1;
	a[1][0]=t2, a[1][1]=0;
	c[0][0]=c[1][1]=1;
	for(ll tt=n-2; tt; tt>>=1, mul(a, a, a, 2, 2, 2)) {
		if(tt&1) {
			mul(c, a, c, 2, 2, 2);
		}
	}
	ll a2=(b*b+d)/2, a1=b;
	CK(a1), CK(a2);
	ll ans;
	CK(ans=mul(a2, c[0][0])+mul(a1, c[1][0]));
	if(b*b!=d && (n&1)==0) {
		if(ans==0) {
			ans=mo-1;
		}
		else {
			ans--;
		}
	}
	printf("%llu\n", ans);
	return 0;
}
