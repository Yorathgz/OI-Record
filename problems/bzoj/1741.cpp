#include<cstdio>
#include<cstring>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int maxn=505;
const int maxk=1e5+5;
int n,k;
struct edge{int v,p;}e[maxk<<1];
int tot,last[maxn],mtc[maxn],usd[maxn],ans;
inline void insert(int u,int v){e[++tot]=(edge){v,last[u]};last[u]=tot;}

inline bool find(int x){
	for(int i=last[x];i;i=e[i].p){
		if(!usd[e[i].v]){
			usd[e[i].v]=1;
			if(!mtc[e[i].v]||find(mtc[e[i].v])){
				mtc[e[i].v]=x;
				return true;
			}
		}
	}
	return false;
}

int main(){
	n=read();k=read();
	int x,y;
	while(k--){
		x=read();y=read();
		insert(x,y);
	}
	for(int i=1;i<=n;i++){
		clr(usd,0);
		if(find(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
