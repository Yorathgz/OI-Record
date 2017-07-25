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

#define P 1000000007
#define MAXN 10000010
using namespace std;
int T,n,a,b,c;
bool not_prime[MAXN];
int prime[MAXN],top;
int sqr[MAXN],cnt[MAXN],minn[MAXN],d[MAXN];
//sqr 约数平方  cnt 约数个数   minn 最小质因子次数  d  除去最小质因子的约数 
int ans1,ans2;
void check()
{
	sqr[1]=1;cnt[1]=1;
	for (int i=2;i<=c;i++)
	{
		if (!not_prime[i])  cnt[i]=2,sqr[i]=(1ll*i*i+1)%P,prime[++top]=i,minn[i]=d[i]=1;
		//cnt - g sqr -  f d - d minn - e
		for (int j=1;j<=top&&i*prime[j]<=c;j++)
		{
			not_prime[i*prime[j]]=1;minn[i*prime[j]]=1;
			d[i*prime[j]]=i;cnt[i*prime[j]]=cnt[i]<<1;
			sqr[i*prime[j]]=1ll*sqr[i]*((1ll*prime[j]*prime[j]+1)%P)%P;
			if (i%prime[j]==0)
			{
				minn[i*prime[j]]=minn[i]+1;d[i*prime[j]]=d[i];
				cnt[i*prime[j]]=(cnt[i]/(minn[i]+1))*(minn[i*prime[j]]+1);
				sqr[i*prime[j]]=(1ll*sqr[i]*(1ll*prime[j]*prime[j]%P)+sqr[d[i]])%P;
				break;
			}
		}
	}
}
int main()
{
	cin>>T>>n>>a>>b>>c;a%=c;b%=c;
	check();
	while (T--)
	{
		ans1+=cnt[n]+(n&1);ans2+=sqr[n]+(n&1)*4;
		if (ans1>=P)    ans1%=P;
		if (ans2>=P)    ans2%=P;
		n=(1ll*n*a+b)%c+1;
	}
	cout<<ans1<<endl<<ans2<<endl;
}
