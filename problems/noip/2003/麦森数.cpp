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
//type18,

#define maxn 501
typedef struct
{
	long a[maxn];
}bign;
void mul(bign &c,bign &a,bign &b)
{
	memset(c.a,0,sizeof(c.a));
	for(int i=0;i<=499;i++)
		for(int j=0;j<=499-i;j++)
			c.a[i+j]+=a.a[i]*b.a[j];
	for(int i=0;i<=499;i++)
		if(c.a[i]>=10)
		{
			c.a[i+1]+=c.a[i]/10;
			c.a[i]%=10;
		}
}
int main()
{
	long n,m,count;
	bign d[maxn]={{1},{2}},ans={{1}},t;
	cin>>n;
	cout<<int(n*log10(2)+1);
	m=int(log(n)/log(2)+3);
	for(int i=2;i<=m;i++)
		mul(d[i],d[i-1],d[i-1]);
	count=0;
	while(n>0)
	{
		if(n%2==1)
		{
			t=ans;
			mul(ans,t,d[count+1]);
		}
		count++;n/=2;
	}
	ans.a[0]--;
	for(int i=499;i>=0;i--)
	{
		if((i+1)%50==0)cout<<endl;
		cout<<ans.a[i];
	}
	//system("pause");
	return 0;
}
