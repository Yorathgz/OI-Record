#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
const double inf=999.9;
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
//type5 
//algorithm: dijkstra
//url: http://hzwer.com/111.html

int n,m;
int s,t;
int x[101],y[101];
double e[1001][1001]; 
double dis[101];
bool book[101]={false};

double getdis(int a,int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=inf;
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),e[i][i]=0;
	cin>>m;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		e[a][b]=e[b][a]=getdis(a,b);
	}
	cin>>s>>t;
	for(int i=1;i<=n;i++)
		dis[i]=e[s][i];
	book[s]=1;
	int mn,u;
	for(int i=1;i<n;i++)
	{
		mn=inf;
		for(int j=1;j<=n;j++)
			if(!book[j]&&dis[j]<mn)
			{
				mn=dis[j];
				u=j;
			}
		book[u]=true;
		for(int j=1;j<=n;j++)
			dis[j]=min(dis[j],dis[u]+e[u][j]);
	}
	printf("%.2lf",dis[t]);
	return 0;
}
