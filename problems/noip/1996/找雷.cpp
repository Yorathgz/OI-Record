#include<iostream>
#include<cstdlib>
#include<algorithm>
#define inf 0xffffff
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
//type3,type4 

int main()
{
    long f[201]={0},w[201],c[201]={0};
    bool pd[201][201]={0};
    long i,j,n,x,y,l,k,mx;
    cin>>n;
    for(i=1;i<=n;i++)
		cin>>w[i];
	do
	{
		cin>>x>>y;
		if(x!=0&&y!=0)pd[x][y]=1;
	}while(x!=0||y!=0);
    f[n]=w[n];
    for(i=n-1;i>=1;i--)
    {
		l=0;k=0;
		for(j=i+1;j<=n;j++)
			if(pd[i][j]==1&&f[j]>l){l=f[j];k=j;}
		f[i]=l+w[i];
		c[i]=k;
	}
	k=1;
	for(j=2;j<=n;j++)
		if(f[j]>f[k])k=j;
	mx=f[k];
	cout<<k;
	k=c[k];
	while(k!=0)
	{
		cout<<'-'<<k;
		k=c[k];
	}
	cout<<endl<<mx<<endl;
	return 0;
}
