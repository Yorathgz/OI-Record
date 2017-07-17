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

int getnum(int t)
{
	if(t<=0) return 1;
	if(0<t&&t<=4) return t;
	int cow=0;
	return cow;
}

int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n&&m)
		cout<<getnum(n)<<endl;
	return 0;
}