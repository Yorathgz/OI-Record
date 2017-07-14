#include<iostream>
#include<cstdlib>
#include<cstring>
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
//type1

int w[10001];
int n,m;

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	int mx=0;
	if(n<=m)
	{
		for(int i=1;i<=n;i++)
			mx=max(mx,w[i]);
		cout<<mx;
		return 0;
	}
	int mn;
	int head=m+1;
	int mark;
	while(head<=n)
	{
		mn=0xffffff;
		for(int i=1;i<=m;i++)
			if(w[i]<mn)
			{
				mn=w[i];
				mark=i;
			}
		w[mark]+=w[head++];
	}
	for(int i=1;i<=m;i++)
		mx=max(mx,w[i]);
	cout<<mx;
	return 0;
}
