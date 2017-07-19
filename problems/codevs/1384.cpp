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

int get(int y,int m)
{
	int i;
	if((y%4==0&&y%100!=0)||(y%400==0)) i=1;
	else i=0;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	else if (m==2)
	{
		if(i==1)
			return 29;
		else return 28;
	}
	return 30;
}

int main()
{
	int n,a[7]={0},week=6;cin>>n;
	for(int i=1900;i<=1900+n-1;i++)
		for(int j=1;j<=12;j++)
		{
			a[week%7]++;
			week+=get(i,j);
		}
	cout<<a[6]<<" "<<a[0]<<" ";
	for(int i=1;i<=5;i++)
		cout<<a[i]<<" ";
	return 0;
}
