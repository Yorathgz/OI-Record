#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=0;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int mod=1e8;
int m,n,ed,ans;
int e[13],f[13][4096];

inline void dp(){
	ed=(1<<n)-1;
	for(int i=0;i<=ed;i++)
		if(!(i&(i>>1))&&(i|e[1])==e[1])
			f[1][i]=1;
	for(int i=2;i<=m;i++)
		for(int j=0;j<=ed;j++)
			if(f[i-1][j])
				for(int k=0;k<=ed;k++)
					if(!(j&k)&&(k|e[i])==e[i]&&!(k&(k>>1)))
						f[i][k]=(f[i][k]+f[i-1][j])%mod;
	for(int i=0;i<=ed;i++)
		ans=(ans+f[m][i])%mod;
}

int main(){
	m=read();n=read();
	for(int i=1,j,t;i<=m;i++)
		for(j=1;j<=n;j++){
			t=read();e[i]<<=1;e[i]+=t;
		}
	dp();
	printf("%d\n",ans);
	return 0;
}
