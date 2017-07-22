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
int t[1000001];  
int ans;  
int num=0;  
int work[100001];  
int x;  
main()  
{  
	scanf("%d%d",&n,&m);  
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);  
	sort(t+1,t+n+1);  
	int i=n;  
	while (i>=1)  
	{  
		num++;  
		if (num==m+1)   
		{  
			int k=*min_element(work+1,work+m+1);  
			num=1;  
			ans+=k-x;  
			x=k;  
		}  
		if (work[num]-x==0)   
		{  
			work[num]+=t[i--];  
		}  
	}  
	ans+=*max_element(work+1,work+m+1)-x;  
	cout<<ans;
}	
