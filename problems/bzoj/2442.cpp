#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=1e5+5;
int n,k,l,r,e[maxn],q[maxn];
ll sum,ans,f[maxn]; //fi: 到i并不选i的损失值

int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)
		e[i]=read(),sum+=e[i];
	l=r=1;q[l]=0;f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[q[l]]+e[i];
		while(l<=r&&f[q[r]]>=f[i]) r--;
		q[++r]=i;
		while(l<=r&&q[l]<i-k) l++;
	}
	ans=f[n];
	for(int i=n-k;i<n;i++) ans=min(ans,f[i]);
	printf("%lld\n",sum-ans);
	return 0;
}
