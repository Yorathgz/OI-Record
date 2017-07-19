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
//type1,

int main()
{
	string a;
	char c;
	double sz=0,x=0,cs=0;
	int i;
	bool fh=1;
	cin>>a;
	for(i=0;i<a.length();i++)
		if(a[i]<='z'&&a[i]>='a')c=a[i];
	for(i=0;a[i]!='=';i++){
		if(a[i]>='0'&&a[i]<='9')
		{sz*=10;sz+=a[i]-'0';}
		else if(a[i]==c)
		{
			if(sz==0)sz=1;
			if(fh==1)x+=sz; 
			if(fh==0)x-=sz;
			sz=0;
		}
		else
		{
			if(fh==0)cs+=sz;
			if(fh==1)cs-=sz;
			sz=0;
			if(a[i]=='-')fh=0;
			if(a[i]=='+')fh=1;
		}
	}
	if(sz!=0)
	{
		if(fh==1)cs-=sz;
		if(fh==0)cs+=sz;
		sz=0;
	}
	fh=1;
	for(;i<=a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			sz*=10;
			sz+=a[i]-'0';
		}
		else if(a[i]==c)
		{
			if(sz==0)sz=1;
			if(fh==0)x+=sz;
			if(fh==1)x-=sz;
			sz=0;
		}
		else
		{
			if(fh==1)cs+=sz;
			if(fh==0)cs-=sz;
			sz=0;
			if(a[i]=='-')fh=0;
			if(a[i]=='+')fh=1;
		}
	}
	cout<<c<<'=';
	if(cs/x<=0&&cs/x>-0.0005)cout<<"0.000";
	else printf("%.3f",cs/x);
	return 0;
}
