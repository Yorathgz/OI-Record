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

#define lchild rt<<1,l,mid
#define rchild rt<<1|1,mid+1,r
#define ln rt<<1
#define rn rt<<1|1
#define MAXN 100010
#define SIZE 6000000
#define GET (ch>='0'&&ch<='9')
using namespace std;
void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
int n,m,cnt,maxn;
int a[MAXN],sta[MAXN];
int root[MAXN],ls[SIZE],rs[SIZE],sum[SIZE];
void ins(int x,int &y,int l,int r,int val)
{
	sum[y=++cnt]=sum[x]+val;
	if (l==r)   return;
	ls[y]=ls[x];rs[y]=rs[x];int mid=(l+r)>>1;
	if (val<=mid)   ins(ls[x],ls[y],l,mid,val);
	else    ins(rs[x],rs[y],mid+1,r,val);
}
int query(int x,int y,int l,int r,int val)
{
	if (l>val||!(sum[y]-sum[x]))    return 0;
	if (val>=r) return sum[y]-sum[x];
	int mid=(l+r)>>1,ret=0;
	(ret=query(ls[x],ls[y],l,mid,val))+=(val>mid?query(rs[x],rs[y],mid+1,r,val):0);
	return ret;
}
int ask(int l,int r)
{
	for (int i=1,last;;i=last+1)    if ((last=query(root[l],root[r],1,maxn,i))<i)   return i;
}
int main()
{
	in(n);int l,r;
	for (int i=1;i<=n;i++)  in(a[i]),maxn=max(maxn,a[i]);
	for (int i=1;i<=n;i++)  ins(root[i-1],root[i],1,maxn,a[i]);
	for (in(m);m;m--)   in(l),in(r),printf("%d\n",ask(l-1,r));
}
