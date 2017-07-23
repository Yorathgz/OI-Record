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

inline void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
int n,m,cmp_d,ans,root;
int a,b,l,r;
int pre[MAXN],nxt[MAXN],lst[MAXN],w[MAXN];
struct KDtree
{
	int ch[2],d[Dnum],minn[Dnum],maxn[Dnum],val,maxv;
	inline void init()  {   for (int i=0;i<Dnum;++i)    minn[i]=maxn[i]=d[i];   }
	inline bool operator < (const KDtree& a)const   {   return d[cmp_d]<a.d[cmp_d]; }
}tree[MAXN];
inline void push_up(int rt)
{
	tree[rt].maxv=tree[rt].val;
	for (int i=0,x=0;i<2;++i)
		if ((x=tree[rt].ch[i]))
		{
			for (int j=0;j<Dnum;++j)
				tree[rt].minn[j]=min(tree[rt].minn[j],tree[x].minn[j]),
					tree[rt].maxn[j]=max(tree[rt].maxn[j],tree[x].maxn[j]);
			tree[rt].maxv=max(tree[rt].maxv,tree[x].maxv);
		}
}
int rebuild(int l=1,int r=n,int d=0)
{
	cmp_d=d;int mid=(l+r)>>1,nxtd=(d+1)%3;nth_element(tree+l,tree+mid,tree+r+1);
	tree[mid].init();
	if (l!=mid) tree[mid].ch[0]=rebuild(l,mid-1,nxtd);
	if (r!=mid) tree[mid].ch[1]=rebuild(mid+1,r,nxtd);
	return push_up(mid),mid;
}
inline bool check(int rt)
{
	if (tree[rt].maxn[1]<=r||tree[rt].minn[2]>=l||tree[rt].minn[0]>r||tree[rt].maxn[0]<l)   return 0;
	return 1;
}
void query(int rt=root)
{
	if (tree[rt].minn[0]>=l&&tree[rt].maxn[0]<=r&&tree[rt].minn[1]>r&&tree[rt].maxn[2]<l)   {   ans=max(ans,tree[rt].maxv);return;  }
	if (tree[rt].d[0]>=l&&tree[rt].d[0]<=r&&tree[rt].d[1]>r&&tree[rt].d[2]<l)   ans=max(ans,tree[rt].val);
	int ls=tree[rt].ch[0],rs=tree[rt].ch[1];
	if (tree[ls].maxv>tree[rs].maxv)
	{
		if (ls&&tree[ls].maxv>ans&&check(ls))   query(ls);
		if (rs&&tree[rs].maxv>ans&&check(rs))   query(rs);
	}
	else
	{
		if (rs&&tree[rs].maxv>ans&&check(rs))   query(rs);
		if (ls&&tree[ls].maxv>ans&&check(ls))   query(ls);
	}
}
int main()
{
	in(n);in(m);
	for (int i=1;i<=n;i++)  in(w[i]),pre[i]=lst[w[i]],lst[w[i]]=i;
	for (int i=1;i<=n;i++)  nxt[pre[i]]=i;nxt[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (!nxt[i])    nxt[i]=n+1;
		tree[i].d[0]=i;tree[i].d[1]=nxt[i];tree[i].d[2]=pre[i];tree[i].val=w[i];
	}
	for (root=rebuild();m;m--)
	{
		in(a);in(b);l=min((a+ans)%n+1,(b+ans)%n+1);r=max((a+ans)%n+1,(b+ans)%n+1);
		ans=0;query();printf("%d\n",ans);
	}
}
