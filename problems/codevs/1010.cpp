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
//type3, type11
//url: http://codevs.cn/problem/1010/

int n,m;
int hx,hy;
int ans;

bool ishorse(int x,int y,int hx,int hy)
{
	if(x==hx&&y==hy)
		return true;
	if(x-1==hx&&y-2==hy)
		return true;
	if(x-2==hx&&y-1==hy)
		return true;
	if(x+1==hx&&y+2==hy)
		return true;
	if(x+2==hx&&y+1==hy)
		return true;
	if(x+2==hx&&y-1==hy)
		return true;
	if(x+1==hx&&y-2==hy)
		return true;
	if(x-1==hx&&y+2==hy)
		return true;
	if(x-2==hx&&y+1==hy)
		return true;
		
	return false;
}

void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		ans++;
		return;
	}

	if(ishorse(x,y,hx,hy))
		return;

	if(x>n||y>m)
		return;

	dfs(x+1,y);
	dfs(x,y+1);
	return;
}

int main()
{
	cin>>n>>m>>hx>>hy;
	dfs(0,0);
	cout<<ans;
	return 0;
}