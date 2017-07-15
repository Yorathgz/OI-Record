#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
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
//type3, type7
//url: http://hzwer.com/94.html

int main()
{
    int m,n;
    cin>>m>>n;
    int s[200]={0};
    int w[31],cost[31];
    for(int i=1;i<=n;i++)
		cin>>w[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int v=w[i];v<=m;v++) 
			if(s[v-w[i]]+c[i]>s[v]) s[v]=s[v-w[i]]+c[i];
	cout<<"max="<<s[m];
	return 0;
}
