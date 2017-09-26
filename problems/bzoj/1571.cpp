#include<cstdio>
#include<cstring>
#include<iostream>
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

const int inf=0x3f3f3f3f;
int t,s,n,po[105],cls[10005][105],f[10005][105],g[10005];

int main(){
	clr(po,0x3f);clr(f,128);
	t=read();s=read();n=read();
	for(int i=1,m,l,a;i<=s;i++)
		m=read(),l=read(),a=read(),
		cls[m+l-1][a]=max(cls[m+l-1][a],m);
	for(int i=1,c,d;i<=n;i++){
		c=read(),d=read();
		for(int j=c;j<=100;j++)
			po[j]=min(po[j],d);
	}
	f[0][1]=g[0]=0;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=100;j++){
			f[i][j]=f[i-1][j];
			if(cls[i-1][j]) f[i][j]=max(f[i][j],g[cls[i-1][j]]);
			if(i-po[j]>=0) f[i][j]=max(f[i][j],f[i-po[j]][j]+1);
			g[i]=max(g[i],f[i][j]);
		}
	printf("%d\n",g[t]);
	return 0;
}
