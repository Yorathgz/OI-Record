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

	template<class classname>
inline void in(classname &x)
{
	char ch=getchar();x=0;int flag=1;
	while (!GET)    flag=ch=='-'?-1:1,ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();x*=flag;
}
int ans,T,n,k;
int c[MAXN],sta[MAXN];
int last[MAXN],pos[MAXN],l[MAXN],r[MAXN];
struct node {   int x,y,w,id;   }s[MAXN];
inline void add(int x,int val)  {   for (;x<=n+1;x+=lowbit(x))  c[x]+=val;  }
inline int query(int x)
{
	int ret=0;
	for (;x;x-=lowbit(x))   ret+=c[x];
	return ret;
}
inline bool cmpx(node a,node b) {   return a.x<b.x; }
inline bool cmpy(node a,node b) {   return a.y<b.y; }
void solve()
{
	memset(last,0,sizeof(last));memset(c,0,sizeof(c));
	sort(s+1,s+n+1,cmpx);pos[0]=0;pos[n+1]=n+1;
	for (int i=1;i<=n;++i)  add(s[i].x,1);
	for (int i=1;i<=n;++i)
	{
		int now=s[i].id,L=last[s[i].w];
		l[now]=L;r[now]=n+1;last[s[i].w]=now;
		if (L)  r[L]=now;
		if (pos[L]+1<=pos[now]-1)   ans=max(ans,query(pos[now]-1)-query(pos[L]));
	}
	for (int i=1;i<=k;i++)  if (pos[last[i]]+1<=n)  ans=max(ans,query(n+1)-query(pos[last[i]]));
	sort(s+1,s+n+1,cmpy);
	for (int i=1,j=1;i<=n;++i)
	{
		int now=s[i].id;
		while (j<=n&&s[j].y==s[i].y)    add(s[j++].x,-1);
		l[r[now]]=l[now];r[l[now]]=r[now];
		if (pos[r[now]]-1>=pos[l[now]]+1)   ans=max(ans,query(pos[r[now]]-1)-query(pos[l[now]]));
	}
}
int main()
{
	for (in(T);T;T--)
	{
		ans=0;in(n);in(k);
		for (int i=1;i<=n;++i)  in(s[i].x),in(s[i].y),in(s[i].w),s[i].id=i,sta[i]=s[i].x;
		sort(sta+1,sta+n+1);
		for (int i=1;i<=n;++i)  s[i].x=lower_bound(sta+1,sta+n+1,s[i].x)-sta,pos[i]=s[i].x;
		solve();
		for (int i=1;i<=n;++i)  s[i].y=-s[i].y;
		solve();
		printf("%d\n",ans);
	}
}
