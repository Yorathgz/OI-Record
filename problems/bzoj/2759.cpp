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

#define MAXN 30010
#define P 10007
#define GET (ch>='0'&&ch<='9')
#define is_root(x) (tree[tree[x].fa].ch[0]!=x&&tree[tree[x].fa].ch[1]!=x)
using namespace std;
int n,q,dfn;
int vis[MAXN],p[MAXN];
int sta[MAXN],top;
struct data
{
	int k,b;
	friend data operator +(const data &x,const data &y) {   return (data){x.k*y.k%P,(x.b*y.k+y.b)%P};   }
	int calc(int x) {   return (k*x+b)%P;   }
};
struct node {   int x,y;    };
struct tree
{
	int ch[2],fa,fa2;
	data val,sum;
	bool rev;
}tree[MAXN];
inline void push_up(int x)  {   tree[x].sum=tree[tree[x].ch[0]].sum+tree[x].val+tree[tree[x].ch[1]].sum;    }
inline void push_down(int x)
{
	if (!x) return;
	if (tree[x].rev)
	{
		tree[tree[x].ch[0]].rev^=1;tree[tree[x].ch[1]].rev^=1;
		swap(tree[x].ch[0],tree[x].ch[1]);tree[x].rev^=1;
	}
}
inline void rot(int x)
{
	int y=tree[x].fa,z=tree[y].fa,l=(tree[y].ch[1]==x),r=l^1;
	if (!is_root(y))    tree[z].ch[tree[z].ch[1]==y]=x;
	tree[y].fa=x;tree[tree[x].ch[r]].fa=y;tree[x].fa=z;
	tree[y].ch[l]=tree[x].ch[r];tree[x].ch[r]=y;
	push_up(y);push_up(x);
}
inline void Splay(int x)
{
	top=0;sta[++top]=x;
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
inline void make_root(int x)    {   access(x);Splay(x);tree[x].rev^=1;  }
inline void link(int x,int y)   {   make_root(x);tree[x].fa=y;  }
inline void cut(int x,int y)    {   make_root(x);access(y);Splay(y);tree[x].fa=tree[y].ch[0]=0;push_up(y);  }
inline void split(int x,int y)  {   make_root(x);access(y);Splay(y);    }
inline int find_root(int x) {   for (access(x),Splay(x);tree[x].ch[0];x=tree[x].ch[0]);return x;    }
node exgcd(int x,int y)
{
	if  (!y)    return (node){1,0};
	node t=exgcd(y,x%y);return (node){t.y,t.x-x/y*t.y};
}
inline int inv(int x)   {   return (exgcd((x+P)%P,P).x+P)%P;    }
inline int query(int x)
{
	int root=find_root(x);
	access(tree[root].fa2);Splay(tree[root].fa2);
	int k=tree[tree[root].fa2].sum.k,b=tree[tree[root].fa2].sum.b;
	if (k==1)   return b==0?-2:-1;
	int tmp=(P-b)*inv(k-1)%P;
	access(x);Splay(x);return tree[x].sum.calc(tmp);
}
inline void modify(int x,int k,int b,int f)
{
	int root=find_root(x);
	tree[x].val.k=k;tree[x].val.b=b;push_up(x);
	if (x==root)    tree[x].fa2=0;
	else
	{
		access(x);Splay(x);
		tree[tree[x].ch[0]].fa=0;tree[x].ch[0]=0;
		push_up(x);
		if (find_root(tree[root].fa2)!=root)
			access(root),Splay(root),
				tree[root].fa=tree[root].fa2,tree[root].fa2=0;
	}
	access(x);Splay(x);
	if (find_root(f)==x)    tree[x].fa2=f;
	else    tree[x].fa=f;
}
void dfs(int x)
{
	vis[x]=dfn;
	if (vis[p[x]]==dfn) {   tree[x].fa2=p[x];return;    }
	tree[x].fa=p[x];
	if (!vis[p[x]]) dfs(p[x]);
}
inline void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
int main()
{
	in(n);int x,k,f,b;char ch[3];
	tree[0].val.k=tree[0].sum.k=1;tree[0].val.b=tree[0].sum.b=0;
	for (int i=1;i<=n;i++)  
		in(k),in(f),in(b),p[i]=f,
			tree[i].val.k=k,tree[i].val.b=b,
			tree[i].sum.k=k,tree[i].sum.b=b;
	for (int i=1;i<=n;i++)  if (!vis[i])    ++dfn,dfs(i);
	for (in(q);q;q--)
	{
		scanf("%s",ch);
		if (ch[0]=='A') in(x),printf("%d\n",query(x));
		else    in(x),in(k),in(f),in(b),modify(x,k,b,f);
	}
}
