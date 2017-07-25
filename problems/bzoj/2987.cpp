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

#define LL long long
using namespace std;
LL calc(LL n,LL a,LL b,LL c)
{
	LL ret=0;
	if (!n) return ret;
	if (c<0)
	{
		LL t=(a-c-1)/a;
		ret-=t*n;c+=t*a;
	}
	if (c/a>0||b/a>0)
	{
		ret+=c/a*n;ret+=b/a*n*(n+1)/2;
		c%=a;b%=a;
	}
	LL newn=(b*n+c)/a;
	ret+=newn*(n+1);ret-=calc(newn,b,a,b-c-1);
	return ret;
}
int main()
{
	LL a,b,c,ans=0;cin>>a>>b>>c;
	LL minn=(c-a)/b,tmp=(b+a-1)/a;
	ans-=tmp*(minn+1)*minn/2;ans+=c/a+c/b+1;
	cout<<ans+calc(minn,a,tmp*a-b,c);
}
