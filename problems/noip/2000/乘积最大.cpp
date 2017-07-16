#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
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
//type3, type8
//url: http://hzwer.com/120.html

long long a[11][11],f[11][11];
long long s;
int n,k1;

int main()
{
	cin>>n>>k1;
	cin>>s;
	for(int i=n;i>=1;i--)
		a[i][i]=s%10,s/=10;
	for(int i=2;i<=n;i++)
		for(int j=i-1;j>=1;j--)
			a[j][i]=a[j][i-1]*10+a[i][i];
	for(int i=1;i<=n;i++)
		f[i][0]=a[1][i];
	for(int k=1;k<=k1;k++)
		for(int i=k+1;i<=n;i++)
			for(int j=k;j<i;j++)
				f[i][k]=max(f[i][k],f[j][k-1]*a[j+1][i]);
	cout<<f[n][k1];
	return 0;
}
