#include<cstdio>
using namespace std;
typedef long long ll;

const int mod=1000000007;
ll n,k;

ll pow(ll a,ll b)
{
	if (b==0) return 1;
	ll t=pow(a,b>>1);
	if (b&1) return t*t%mod*a%mod;
	return t*t%mod;
}

int main(){
	freopen("sets.in","r",stdin);
	freopen("sets.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",pow(pow(2,k)-1,n));
	return 0;
}
