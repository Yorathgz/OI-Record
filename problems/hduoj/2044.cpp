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

int main()
{
	long long i[100],a,b;
	int n,k;
	cin>>n;
	i[1]=1;i[2]=2;
	for(k=3;k<=51;k++)
		i[k]=i[k-1]+i[k-2];
	while(n--)
	{
		cin>>a>>b;
		cout<<i[b-a];
	}
	return 0;
}