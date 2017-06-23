#include<cstdio>
#define ll long long
inline ll read()
{
	ll x=0,f=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(ll x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

ll ans=1;
int n,P,cnt;
int pri[1000005],mn[2000005],num[2000005];
bool del[2000005];

void getpri()
{
	for(int i=2;i<=2*n;i++)
	{
		if(!del[i])pri[++cnt]=i,mn[i]=cnt;
		for(int j=1;pri[j]*i<=2*n&&j<=cnt;j++)
		{
			del[pri[j]*i]=1;mn[pri[j]*i]=j;
			if(i%pri[j]==0)break;
		}
	}
}

void add(int x,int f)
{
	while(x!=1)
	{
		num[mn[x]]+=f;
		x/=pri[mn[x]];
	}
}

int main()
{
	n=read();P=read();
	getpri();
	for(int i=2*n;i>n;i--)add(i,1);
	for(int i=1;i<=n;i++)add(i,-1);
	add(n+1,-1);
	for(int i=1;i<=cnt;i++)
		while(num[i]--)ans=(ans*pri[i])%P;
	write(ans);
	return 0;
}