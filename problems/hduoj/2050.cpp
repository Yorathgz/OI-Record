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
	ios::sync_with_stdio(0);
	int c;
	cin>>c;
	
	int num[10005];
	num[1]=2;
	for(int i=2;i<=1003;i++)
		num[i]=num[i-1]+4*(i-1)+1;
	int a;
	while(c--)
	{
		cin>>a;
		cout<<num[a]<<endl;
	}
	return 0;
}