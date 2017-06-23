#include<cstdio> 
#include<algorithm>
using namespace std;

inline int read()
{
	register int x=0,f=1;register char ch=0;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int size=1<<11;
const int mod=1e9+9;
int n,k;
int tag[size],med[size];
int next[size];
int fact[size];
int f[size][size];
int C[size][size];
inline int add(int,int);
inline int sub(int,int);
inline int mul(int,int);
inline void init();

int main()
{
	n=read();k=read();
	if((n-k)&1)
	{
		putchar('0');
		return 0;
	}
	k=(n+k)>>1;
	for(int i=1;i<=n;i++) tag[i]=read();
	for(int i=1;i<=n;i++) med[i]=read();
	
	init();
	
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(j&&next[i]-j+1>0)
				f[i][j]=add(f[i][j],mul(f[i-1][j-1],next[i]-j+1));
		}
	
	for(int i=n;i>=k;i--)
	{
		f[n][i]=mul(f[n][i],fact[n-i]);
		for(int j=i+1;j<=n;j++)
			f[n][i]=sub(f[n][i],mul(f[n][j],C[j][i]));
	}
	
	write(f[n][k]);
	
	return 0;
}

inline int add(int x,int y) {return (x+y)%mod;}
inline int sub(int x,int y) {return (x-y+mod)%mod;}
inline int mul(int x,int y) {return (long long)x*y%mod;}

inline void init()
{
	sort(tag+1,tag+1+n);sort(med+1,med+1+n);
	
	int j=0;
	for(int i=1;i<=n;i++)
	{
		for(;j<n&&tag[i]>med[j+1];j++);
		next[i]=j;
	}
	
	for(int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=mul(fact[i-1],i);
	
	return;
}