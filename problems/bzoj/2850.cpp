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

LL ans;
int n,m,root;
long long a,b,lim;
bool cmp_d;
struct KDtree
{
	int ch[2],d[Dnum],minn[Dnum],maxn[Dnum],val; LL sum;
	inline bool operator < (const KDtree& a)const   {   return d[cmp_d]<a.d[cmp_d]; }
	inline void init()  {   sum=val;    for (int i=0;i<Dnum;++i)    minn[i]=maxn[i]=d[i];   }
}tree[MAXN];
inline bool check(int x,int y)  {   return a*x+b*y<lim; }
inline int calc(int rt)
{
	int ret=0;
	ret+=check(tree[rt].minn[0],tree[rt].minn[1]);ret+=check(tree[rt].minn[0],tree[rt].maxn[1]);
	ret+=check(tree[rt].maxn[0],tree[rt].minn[1]);ret+=check(tree[rt].maxn[0],tree[rt].maxn[1]);
	return ret;
}
inline void push_up(int rt)
{
	tree[rt].sum=tree[rt].val;
	for (int i=0;i<2;++i)
		if (tree[rt].ch[i])
		{
			int x=tree[rt].ch[i];
			tree[rt].sum+=tree[x].sum;
			for (int j=0;j<2;++j)
				tree[rt].minn[j]=min(tree[rt].minn[j],tree[x].minn[j]),
					tree[rt].maxn[j]=max(tree[rt].maxn[j],tree[x].maxn[j]);
		}
}
int rebuild(int l=1,int r=n,bool d=0)
{
	cmp_d=d;int mid=(l+r)>>1;nth_element(tree+l,tree+mid,tree+r+1);
	tree[mid].init();
	if (l!=mid) tree[mid].ch[0]=rebuild(l,mid-1,d^1);
	if (r!=mid) tree[mid].ch[1]=rebuild(mid+1,r,d^1);
	return push_up(mid),mid;
}
void query(int rt=root)
{
	int l=tree[rt].ch[0],r=tree[rt].ch[1],cntl=l?calc(l):0,cntr=r?calc(r):0;
	if (check(tree[rt].d[0],tree[rt].d[1])) ans+=tree[rt].val;
	if (cntl==4)    ans+=tree[l].sum;
	else    if (cntl)   query(l);
	if (cntr==4)    ans+=tree[r].sum;
	else    if (cntr)   query(r);
}
int main()
{
	in(n);in(m);
	for (int i=1;i<=n;i++)  in(tree[i].d[0]),in(tree[i].d[1]),in(tree[i].val);
	for (root=rebuild();m;m--)
	{
		llin(a);llin(b);llin(lim);ans=0;
		query();printf("%lld\n",ans);
	}
}
