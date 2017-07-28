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
//type20, 

int n,m;
long long in[100000],ask;

void ans(int x)
{
	if(n==1)
	{
		cout<<in[0]<<endl;
		return;
	}
	
	int lf=0,rt=n-1,mid;
	while(lf<rt-1)
	{
		mid=(lf+rt)>>1;
		if(in[mid]>x) rt=mid;
		else lf=mid;
	}
	if(lf==rt)
		cout<<in[mid]<<endl;
	else if((x-in[lf])>(in[rt]-x))
		cout<<in[rt]<<endl;
	else
		cout<<in[lf]<<endl;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i];
	sort(in,in+n);
	
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>ask,
		ans(ask);
	
	return 0;
}