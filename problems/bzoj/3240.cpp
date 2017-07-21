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

const int mo=1e9+7;
int ipow(int a, int b) {
	if(a>=mo) {
		a%=mo;
	}
	int x=1;
	for(; b; b>>=1, a=(ll)a*a%mo) {
		if(b&1) {
			x=(ll)x*a%mo;
		}
	}
	return x;
}
void getint(int &n, int &nn) {
	char c=getchar();
	n=nn=0;
	for(; c<'0'||c>'9'; c=getchar());
	for(; c>='0'&&c<='9'; c=getchar()) {
		n=((ll)n*10+c-'0')%mo;
		nn=((ll)nn*10+c-'0')%(mo-1);
	}
}
int main() {
	int n, m, nn, mm, a, b, c, d, ans;
	getint(n, nn);
	getint(m, mm);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int k, j;
	if(a==1) {
		k=c;
		j=((ll)c*(m-1+mo)%mo*b%mo+d)%mo;
	}
	else {
		int p=ipow(a, mm-1+(mo-1));
		k=(ll)c*p%mo;
		j=((ll)b*c%mo*(1-p+mo)%mo*ipow(1-a+mo, mo-2)%mo+d)%mo;
	}
	if(k==1) {
		ans=((ll)n*j%mo+1)%mo;
	}
	else {
		int p=ipow(k, nn);
		ans=((ll)j*ipow(1-k+mo, mo-2)%mo*(1-p+mo)%mo+p)%mo;
	}
	ans=(ans-d+mo)%mo;
	ans=(ll)ans*ipow(c, mo-2)%mo;
	printf("%d\n", ans);
	return 0;
}
