#include<cstdio>
#include<queue>
#include<cstring>
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

const int maxn=1e5+5;
struct node{int d,p;}c[maxn];
bool operator<(const node& a,const node& b){return a.d<b.d;}
int n,cnt;
ll ans;
priority_queue<int,vector<int>,greater<int> > q;

int main(){
	n=read();
	for(int i=1;i<=n;i++) c[i].d=read(),c[i].p=read();
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		ans+=c[i].p;q.push(c[i].p);cnt++;
		if(c[i].d<cnt) ans-=q.top(),q.pop(),cnt--;
	}
	printf("%lld\n",ans);
	return 0;
}
