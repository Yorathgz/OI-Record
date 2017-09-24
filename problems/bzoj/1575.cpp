#include<cstdio>
#include<cmath>
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

const int maxn=105;
const int inf=0x3f3f3f3f;
int n,e,m[maxn],c[maxn][maxn],f[maxn][maxn];

int main(){
	n=read();e=read();
	for(int i=1;i<=n;i++)
		m[i]=read();
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n+1;j++)
			for(int k=i+1;k<j;k++){
				if(i==0) c[i][j]+=2*abs(m[j]-m[k]);
				else if(j==n+1) c[i][j]+=2*abs(m[k]-m[i]);
				else c[i][j]+=abs(2*m[k]-m[i]-m[j]);
			}
	memset(f,0x3f,sizeof(f));
	c[0][n+1]=inf;f[0][1]=0;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i+1;j++)
			for(int k=0;k<i;k++)
				if(j-1<=k+1)
					f[i][j]=min(f[i][j],f[k][j-1]+c[k][i]);
	for(int i=1;i<=n+2;i++)
		if(f[n+1][i]<=e){
			printf("%d %d\n",i-2,f[n+1][i]);
			return 0;
		}
}
