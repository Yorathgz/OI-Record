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
//type19, type20, 

int n,i,j,time,head,tail,mid,ans,l,r;
int a[N],q[N],f[N];



int get()
{
	int p=0;
	char x=getchar();
	while(x<'0' || x>'9') x=getchar();
	while(x>='0'&&x<='9')
	{
		p=p*10+x-'0';
		x=getchar();
	}
	return p;
}

int min(int a,int b)
{
	return a>b?b:a;
}



void read()
{
	n=get(); time=get();
	for(i=1;i<=n;++i)
		a[i]=get();
	return;
}



void push(int x)
{
	if (f[x]>=inf) return ;
	while(head<=tail && f[q[tail]]>=f[x]) tail--;
	tail++;	q[tail]=x;
	return;
}



bool judge(int len)
{
	int Min=inf;
	for(i=1;i<=n;++i)
		f[i]=inf;
	f[0]=0;
	head=1; tail=0;
	for(i=1;i<=n;++i)
	{
		push(i-1);
		while(head<=tail && i-1-q[head]>len)
			head++;
		if(head<=tail)
			f[i]=f[q[head]]+a[i];//这个地方注意，队列为空的话其实就代表没有解，所以 if 一下
	}
	for(i=n-len;i<=n;++i)
		Min=min(Min,f[i]);
	if(Min>time)
		return false;
	return true;
}



int main()
{
	read();
	l=0; r=n;
	ans=inf;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(judge(mid))
		{
			ans=min(ans,mid);
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}