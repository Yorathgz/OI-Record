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
//type3, type4

int n;
int num[101];

void getnum(int t)
{
	for(int i=3;i<=t;i++)
		num[i]=num[i-1]+num[i-2];
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	num[1]=num[2]=1;
	getnum(45);
	while(N--)
	{
		int steps;
		cin>>steps;
		cout<<num[steps]<<endl;
	}
	return 0;
}