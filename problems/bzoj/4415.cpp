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
#define MAXN 700010
#define GET (ch>='0'&&ch<='9')
using namespace std;
int n,x;
struct seg
{
	int l,r,msg;
}tree[MAXN*3];
void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
void build(int rt=1,int l=1,int r=n)
{
	tree[rt].l=l;tree[rt].r=r;
	if (l==r)   {   tree[rt].msg=1;return;  }
	int mid=(l+r)>>1;build(lchild);build(rchild);tree[rt].msg=r-l+1;
}
int query(int rt,int x)
{
	int L=tree[rt].l,R=tree[rt].r;
	tree[rt].msg--;return L==R?L:(tree[ln].msg>=x?query(ln,x):query(rn,x-tree[ln].msg));
}
int main()
{
	in(n);build();int now=0;
	while (n--) in(x),(now+=x)%=(n+1),printf("%d\n",query(1,now+1));
}
