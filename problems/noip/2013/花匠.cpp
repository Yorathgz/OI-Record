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
//type1, type3

int a[100001];
int f[100001][2];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=f[i][0]=1;
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>0;j--)
		{
			if(a[j]>a[i])f[i][0]=max(f[j][1]+1,f[i][0]);
			if(a[j]<a[i])f[i][1]=max(f[j][0]+1,f[i][1]);
			if(f[i][0]!=1&&f[i][1]!=1)break;
		}
	cout<<max(f[n][0],f[n][1]);
	return 0;
}
