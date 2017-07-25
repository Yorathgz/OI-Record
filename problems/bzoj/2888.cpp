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

#define MAXN 40010
#define GET (ch>='0'&&ch<='9')
using namespace std;
void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
int n,m,ans,tp;
int sta[MAXN],top;
struct edge {   int to; edge *next; }e[MAXN<<1],*prev[MAXN];
void insert(int u,int v)    {   e[++tp].to=v;e[tp].next=prev[u];prev[u]=&e[tp]; }
struct Splay
{
	int ch[2],fa,size,val,flag;
	int sum,s,d;//s d 等差数列首项/公差  
	bool rev;
}tree[MAXN];
inline bool is_root(int x)  {   return tree[tree[x].fa].ch[0]!=x&&tree[tree[x].fa].ch[1]!=x;    }
inline void push_up(int x)
{   
	if (!x) return;
	tree[x].size=tree[tree[x].ch[0]].size+tree[tree[x].ch[1]].size+1;
}
inline void upd(int x,int delta)
{
	if (!x) return;
	tree[x].val+=delta;tree[x].flag+=delta;
}
inline void update(int x,int s,int d)
{   
	if (!x) return;
	tree[x].sum+=s+tree[tree[x].ch[1]].size*d;
	tree[x].s+=s;tree[x].d+=d;
}
inline void push_down(int x)
{
	int l=tree[x].ch[0],r=tree[x].ch[1];
	if (tree[x].rev)
	{
		tree[l].rev^=1;tree[r].rev^=1;
		swap(tree[x].ch[0],tree[x].ch[1]);tree[x].rev^=1;
	}
	if (tree[x].flag)
	{
		tree[l].val+=tree[x].flag;tree[l].flag+=tree[x].flag;
		tree[r].val+=tree[x].flag;tree[r].flag+=tree[x].flag;
		tree[x].flag=0;
	}
	if (tree[x].d)
	{
		update(l,tree[x].s+(tree[r].size+1)*tree[x].d,tree[x].d);
		update(r,tree[x].s,tree[x].d);
		tree[x].s=tree[x].d=0;
	}
}
inline void rot(int x)
{
	int y=tree[x].fa,z=tree[y].fa,l=(tree[y].ch[1]==x),r=l^1;
	if (!is_root(y))    tree[z].ch[tree[z].ch[1]==y]=x;
	tree[tree[x].ch[r]].fa=y;tree[y].fa=x;tree[x].fa=z;
	tree[y].ch[l]=tree[x].ch[r];tree[x].ch[r]=y;
	push_up(y);push_up(x);
}
inline void Splay(int x)
{
	sta[++top]=x;
	for (int i=x;!is_root(i);i=tree[i].fa)  sta[++top]=tree[i].fa;
	while (top) push_down(sta[top--]);
	while (!is_root(x))
	{
		int y=tree[x].fa,z=tree[y].fa;
		if (!is_root(y))
		{
			if ((tree[y].ch[0]==x)^(tree[z].ch[0]==y))  rot(x);
			else    rot(y);
		}
		rot(x);
	}
}
inline void access(int x)   {   for (int i=0;x;i=x,x=tree[x].fa)    Splay(x),tree[x].ch[1]=i,push_up(x);    }
inline void make_root(int x)    {   access(x);tree[x].rev^=1;   }
inline void link(int x,int y)   {   make_root(x);tree[x].fa=y;  }
inline int find(int x)  {   for (access(x),Splay(x);tree[x].ch[0];x=tree[x].ch[0]); return x;   }
inline void ins(int f,int x)
{
	tree[x].fa=f;tree[x].ch[0]=tree[x].ch[1]=tree[x].val=tree[x].flag=0;
	tree[x].sum=tree[x].s=tree[x].d=0;tree[x].size=1;
	f=find(f);access(x);Splay(f);
	tree[f].val+=1;tree[f].flag+=1;update(f,0,1);
	for (x=tree[f].ch[1];tree[x].ch[0];x=tree[x].ch[0]);
	Splay(x);int v1=tree[f].val,v2=tree[x].val;
	if (v2<<1>v1)
	{
		tree[x].val=v1;tree[f].val-=v2;
		tree[f].sum-=tree[x].sum+v2;tree[x].sum+=tree[f].sum+v1-v2;
		access(x);Splay(f);tree[f].ch[0]=x;tree[f].ch[1]=0;
	}
}
void dfs(int x,int f)
{
	ins(f,x);
	for (edge *i=prev[x];i;i=i->next)   if (i->to!=f)   dfs(i->to,x);
}
void addedge(int x,int y)
{
	int p=find(x),q=find(y);ans-=tree[p].sum+tree[q].sum;
	if (tree[p].val<tree[q].val)    swap(x,y);
	dfs(y,x);insert(x,y);insert(y,x);ans+=tree[find(x)].sum;
}
int main()
{
	char ch[2];int u,v;in(n);
	for (int i=1;i<=n;i++)  tree[i].val=tree[i].size=1;
	for (in(m);m;m--)
	{
		scanf("%s",ch);
		if (ch[0]=='A') in(u),in(v),addedge(u,v);
		if (ch[0]=='Q') printf("%d\n",ans);
	}
}
