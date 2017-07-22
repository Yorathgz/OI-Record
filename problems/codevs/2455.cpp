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
//type19, 

int n,m;  
int x,y,v;  
int ans;  
int maxn;  
struct s  
{  
	int x;  
	int y;  
	int v;  
}a[90001];  
int f[90001];  
int num;  
int k;  
int comp(s a,s b)  
{  
	return a.v<b.v;  
}  
int find(int x)  
{  
	if (f[x]!=x) f[x]=find(f[x]);  
	return f[x];  
}  
int unionn(int a,int b)  
{  
	int fa=find(a);  
	int fb=find(b);  
	if (fa!=fb) f[fa]=fb;  
}  
main()  
{  
	scanf("%d%d",&n,&m);  
	for (int i=1;i<=m;i++)  
	{  
		scanf("%d%d%d",&x,&y,&v);  
		a[++num].x=x;a[num].y=y;a[num].v=v;  
	}  
	for (int i=1;i<=num;i++) f[i]=i;  
	sort(a+1,a+num+1,comp);  
	for (int i=1;i<=num;i++)  
	{  
		if (find(a[i].x)!=find(a[i].y))  
		{  
			unionn(a[i].x,a[i].y);  
			ans++;  
			maxn=max(a[i].v,maxn);  
			k++;  
		}  
		if (k==n-1) break;  
	}  
	cout<<ans<<' '<<maxn;  
}
