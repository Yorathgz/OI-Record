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
//type1, type18

int main ()
{
	int n,l=1,a[1001]={0};
	cin>>n;
	n++;
	a[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=100;j++)
			a[j]*=2;
		for(int j=1;j<=100;j++)
		{
			if(a[j]>=10)
			{
				a[j+1]+=a[j]/10;
				a[j]%=10;
			}
		}
		if(i==n-1)a[1]--;
	}
	for(int i=1;i<=1000;i++)
		if(a[i]!=0)l=max(i,l);
	for(int i=l;i>=1;i--)
		cout<<a[i];
	return 0;
}
