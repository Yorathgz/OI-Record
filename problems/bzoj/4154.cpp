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

int ans;
int T,n,c,q,top,root,dfn,tp;
bool cmp_d;
int In[MAXN],Out[MAXN],deep[MAXN],sta[MAXN],id[MAXN];
struct edge {   int to; edge *next; }e[MAXN],*prev[MAXN];
inline void insert(int u,int v) {   e[++top].to=v;e[top].next=prev[u];prev[u]=&e[top];  }
struct KDtree
{
	int ch[2],d[Dnum],minn[Dnum],maxn[Dnum],tim,col,f,flag;
	inline void init()  {   for (int i=0;i<Dnum;++i)    minn[i]=maxn[i]=d[i];   }
	inline bool operator < (const KDtree& a)const   {   return d[cmp_d]<a.d[cmp_d]; }
}tree[MAXN];
inline void push_up(int rt)
{
	id[tree[rt].flag]=rt;tree[rt].flag=0;tree[rt].col=1;
	for (int i=0,x=0;i<2;++i)
		if ((x=tree[rt].ch[i]))
		{
			for (int j=0;j<Dnum;++j)
				tree[rt].minn[j]=min(tree[rt].minn[j],tree[x].minn[j]),
					tree[rt].maxn[j]=max(tree[rt].maxn[j],tree[x].maxn[j]);
		}
}
inline void push_down(int rt)
{
	int tmp=0;
	if ((tmp=tree[rt].flag))
	{
		for (int i=0,x=0;i<2;++i)   if ((x=tree[rt].ch[i])) tree[x].col=tree[x].flag=tmp;
		tree[rt].flag=0;
	}
}
int rebuild(int l=1,int r=n,bool d=0,int f=0)
{
	cmp_d=d;int mid=(l+r)>>1;nth_element(tree+l,tree+mid,tree+r+1);
	tree[mid].init();tree[mid].f=f;
	if (l!=mid) tree[mid].ch[0]=rebuild(l,mid-1,d^1,mid);
	if (r!=mid) tree[mid].ch[1]=rebuild(mid+1,r,d^1,mid);
	return push_up(mid),mid;
}
int col,x1,x2,y1,y2;
void modify(int rt=root)
{
	if (tree[rt].minn[0]>x2||tree[rt].maxn[0]<x1||tree[rt].maxn[1]<y1||tree[rt].minn[1]>y2) return;
	if (tree[rt].minn[0]>=x1&&tree[rt].maxn[0]<=x2&&tree[rt].minn[1]>=y1&&tree[rt].maxn[1]<=y2) {   tree[rt].col=tree[rt].flag=c;return;    }
	push_down(rt);
	if (tree[rt].d[0]>=x1&&tree[rt].d[0]<=x2&&tree[rt].d[1]>=y1&&tree[rt].d[1]<=y2) tree[rt].col=c;
	for (int i=0,x=0;i<2;++i)   if ((x=tree[rt].ch[i])) modify(x);
}
inline int query(int rt)
{
	for (int i=rt;tree[i].f;i=tree[i].f)    sta[++tp]=tree[i].f;
	while (tp)  push_down(sta[tp--]);return tree[rt].col;
}
void dfs(int x)
{
	tree[x].flag=x;In[x]=tree[x].d[0]=++dfn;tree[x].d[1]=deep[x];
	for (edge *i=prev[x];i;i=i->next)   deep[i->to]=deep[x]+1,dfs(i->to);
	Out[x]=dfn;
}
inline void clear()
{
	for (int i=1;i<=n;i++)  for (int j=0;j<2;++j)   tree[i].ch[j]=0;
}
int main()
{
	for (in(T);T;T--)
	{
		in(n);in(c);in(q);int u,v;dfn=top=0;
		memset(prev+1,0,sizeof(edge*)*(n+1));clear();
		for (int i=2;i<=n;i++)  in(u),insert(u,i);
		dfs(1);root=rebuild();ans=0;
		for (int i=1;i<=q;i++)
		{
			in(u);in(v);in(c);
			if (c)  x1=In[u],x2=Out[u],y1=deep[u],y2=deep[u]+v,modify();
			else    ans=(1ll*query(id[u])*i+ans)%P;
		}
		printf("%d\n",ans);
	}
}
