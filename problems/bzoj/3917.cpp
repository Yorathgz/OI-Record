#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define LL long long
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
//type19, 

int k,b[MAXN];
	template <class classname>
inline void in(classname &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
LL solve(const int a[],int n,bool fla)
{
	LL ret=1ll<<62;
	if (n==1)
	{
		ret=0;
		for (int i=1;i<=9;++i)
			if (a[1]&(1<<i))
			{
				ret=ret*10+i;
				if (ret==i&&(a[1]&1))   ret*=10;
			}
		if (ret==0&&(a[1]&1))   ret=10;
		return ret;
	}
	int tn[MAXN],tp=0;
	for (int i=0;i<9+fla;++i)
	{
		int num=0,now=i;tp=0;bool b=0;
		for (int j=1;j<=n;++j)
		{
			num|=a[j]&(1023-(1<<now));
			if ((a[j]&1)&&now==0)   b=1;
			now++;now=now>=10?now-10:now;
			if (!now||j==n) tn[++tp]=num,num=0;
		}
		LL ans=solve(tn,tp,i<9||n>2)*10+i;
		if (!ans&&b)    ans=10;
		ret=min(ret,ans);
	}
	return ret;
}
int main()
{
	in(k);
	for (int i=1;i<=k;i++)  in(b[i]),b[i]=1<<b[i];
	cout<<solve(b,k,1)<<endl;
}int k,b[MAXN];
	template <class classname>
inline void in(classname &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
LL solve(const int a[],int n,bool fla)
{
	LL ret=1ll<<62;
	if (n==1)
	{
		ret=0;
		for (int i=1;i<=9;++i)
			if (a[1]&(1<<i))
			{
				ret=ret*10+i;
				if (ret==i&&(a[1]&1))   ret*=10;
			}
		if (ret==0&&(a[1]&1))   ret=10;
		return ret;
	}
	int tn[MAXN],tp=0;
	for (int i=0;i<9+fla;++i)
	{
		int num=0,now=i;tp=0;bool b=0;
		for (int j=1;j<=n;++j)
		{
			num|=a[j]&(1023-(1<<now));
			if ((a[j]&1)&&now==0)   b=1;
			now++;now=now>=10?now-10:now;
			if (!now||j==n) tn[++tp]=num,num=0;
		}
		LL ans=solve(tn,tp,i<9||n>2)*10+i;
		if (!ans&&b)    ans=10;
		ret=min(ret,ans);
	}
	return ret;
}
int main()
{
	in(k);
	for (int i=1;i<=k;i++)  in(b[i]),b[i]=1<<b[i];
	cout<<solve(b,k,1)<<endl;
}
