#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define ll long long
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
//type3,

int m,n,a[100001],f[100001],Max;

int main()
{
	cin>>m;
	for(int k=1;k<=m;k++)
	{
		Max=0,n=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(f[i-1]>f[i])f[i]=f[i-1];
			f[i]+=a[i];
			if(f[i]>Max)Max=f[i];
		}
		cout<<Max<<endl;
	}
	return 0;
}
