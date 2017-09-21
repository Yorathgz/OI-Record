#include<cstdio>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=2e5+5;
const ll mod=1e8+7;
ll jc[maxn],ny[maxn];

inline ll ksm(ll a,ll x){
	ll t=1;
	while(x){
		if(x&1) t*=a,t%=mod;
		a*=a;
		a%=mod;
		x>>=1;
	}
	return t;
}

inline void init(){
	jc[0]=1;ny[0]=1;
	for(int i=1;i<maxn;i++){
		jc[i]=jc[i-1]*i%mod;
		ny[i]=ksm(jc[i],mod-2);
	}
}

inline ll C(int n,int m){
	return jc[n]*ny[m]%mod*ny[n-m]%mod;
}

int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	init();
	int m=read(),n=read(),p=read(),q=read();
	printf("%lld\n",(C(n+m,n)*C(m-p+q,q)%mod-C(q+m,q)*C(m-p+n,n)%mod+mod)%mod);
	return 0;
}
