#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define LL long long
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

void query_max(int rt=root)
{
	tmp=max(tmp,dis(tree[rt],qnode));
	int l=tree[rt].ch[0],r=tree[rt].ch[1],disl=l?ask_max(l):-MAXINT,disr=r?ask_max(r):-MAXINT;
	if (disl>disr)
	{
		if (disl>tmp)   query_max(l);
		if (disr>tmp)   query_max(r);
	}
	else
	{
		if (disr>tmp)   query_max(r);
		if (disl>tmp)   query_max(l);
	}
}
void query_min(int rt=root)
{
	int Dis=dis(tree[rt],qnode);if (Dis)    tmp=min(tmp,Dis);
	int l=tree[rt].ch[0],r=tree[rt].ch[1],disl=l?ask_min(l):MAXINT,disr=r?ask_min(r):MAXINT;
	if (disl<disr)
	{
		if (disl<tmp)   query_min(l);
		if (disr<tmp)   query_min(r);
	}
	else
	{
		if (disr<tmp)   query_min(r);
		if (disl<tmp)   query_min(l);
	}
}
int query(bool d,int x,int y)
{
	qnode.d[0]=x;qnode.d[1]=y;
	if (d)  tmp=-MAXINT,query_max();
	else    tmp=MAXINT,query_min();
	return tmp;
}
int main()
{
	in(n);ans=MAXINT;
	for (int i=1;i<=n;i++)  in(x[i]),in(y[i]),tree[i].d[0]=x[i],tree[i].d[1]=y[i];
	root=rebuild();
	for (int i=1;i<=n;i++)
	{
		int minn=query(0,x[i],y[i]),maxn=query(1,x[i],y[i]);
		ans=min(ans,maxn-minn);
	}
	printf("%d\n",ans);
}
