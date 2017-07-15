#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff
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
//type3,type4 
//url: http://hzwer.com/70.html

int main()
{
    int n,sum=0;int a[101];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	sum/=n;
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==sum) continue;
		if(a[i]>sum) a[i+1]+=a[i]-sum;
		if(a[i]<sum) a[i+1]-=sum-a[i];
		count++;
	}
	cout<<count;
	return 0;
}
