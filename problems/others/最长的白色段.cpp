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
	int point[10001];
	int bg[5001],ed[5001],b1,b2,e;
	int mx=0;
	char cr[5001];
	int c[10000];
	int n;
	int i,j,l;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>bg[i]>>ed[i]>>cr[i];
		point[i]=bg[i];
		point[n+i]=ed[i];
	}
	sort(point,point+2*n+1);
	for(i=1;i<2*n;i++)
		for(j=n;j>=0;j--)
			if(point[i]==bg[j]||(bg[j]<=point[i]&&ed[j]>point[i])||j==0)
			{
				if(cr[j]=='w'||j==0){c[i]=point[i+1]-point[i];break;}
				else {c[i]=-1;break;}
			}
	for(i=1;i<2*n;i++)
	{
		j=0,l=0;
		b1=point[i];
		while(c[i+j]!=-1)
		{
			l+=c[i+j];
			if(l>mx){mx=l;b2=b1;e=point[i+j+1];}
			j++;
		}
	}
	cout<<b2<<' '<<e;
	return 0;
}
