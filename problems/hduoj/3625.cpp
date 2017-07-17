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
//type10

#define N 21

ll fac[N]={1,1};
ll stir[N][N];

void init()
{
	int i,j;
	for(int i=2;i<N;i++)
		fac[i]=i*fac[i-1];
	memset(stir,0,sizeof(stir));
	stir[0][0]=0;
	stir[1][1]=1;
	for(int i=2;i<N;i++)
		for(j=1;j<=i;j++)
			stir[i][j]=stir[i-1][j-1]+(i-1)*stir[i-1][j];
}

int main()
{
	init();
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		ll cnt=0;
		for(int i=1;i<=k;i++)
			cin+=stir[n][i]-stir[n-1][i-1];
		printf("%.4lf\n",1.0*cnt/fac[n]);
	}
	return 0;
}