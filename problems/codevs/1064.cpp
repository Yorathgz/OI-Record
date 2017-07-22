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

int n,m;int f[30001];  
int num;  
int find(int x)  
{   
	if (f[x]!=x)   
		f[x]=find(f[x]);  
	return f[x];  
}  
void union_set(int a,int b)  
{   
	int t1,t2;   
	t1=find(a);   
	t2=find(b);   
	if (t1!=t2)   
		f[t2]=t1;  
}  
main()  
{  
	scanf("%d%d",&n,&m);   
	for (int i=1;i<=n;i++)   
		f[i]=i;   
	for (int i=1;i<=m;i++)   
		for (int j=1;j<=3;j++)  
		{  
			int a; scanf("%d",&a);   
			union_set(i,a);  
		}   
	for (int i=1;i<=n;i++)   
		if (f[i]==i) num++;   
	cout<<num;  
}  
