#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=1e4+4;
int n,a[maxn];

int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	printf("%d\n",a[n+1>>1]);
	return 0;
}
