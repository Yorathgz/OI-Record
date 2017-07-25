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

#define MAXN 250010
#define LL long long
#define GET (ch>='0'&&ch<='9')
#define SIZE 1800000
using namespace std;
int n,st,m,cnt;
LL ret,ans;
int root[MAXN];
int b[MAXN],sta[MAXN],c;
int ls[SIZE],rs[SIZE],sz[SIZE];
LL sum[SIZE];
int fd[MAXN],gd[MAXN],f1d[MAXN],g1d[MAXN];
LL f[MAXN],g[MAXN],f1[MAXN],g1[MAXN];
inline void in(int &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
void ins(int x,int &y,int l,int r,int val,LL Val)
{
	sz[y=++cnt]=sz[x]+1;sum[y]=sum[x]+Val;
	ls[y]=ls[x];rs[y]=rs[x];
	if (l==r)   return;
	int mid=(l+r)>>1;
	if (val<=mid)   ins(ls[x],ls[y],l,mid,val,Val);
	else ins(rs[x],rs[y],mid+1,r,val,Val);
}
void query(int x,int y,int l,int r,int k)
{
	if (k<=0)   return;
	if (l==r)   {   ret+=1ll*min(k,sz[y]-sz[x])*sta[l];return;  }
	int mid=(l+r)>>1;
	//if (sz[ls[y]]-sz[ls[x]]>=k)   query(ls[x],ls[y],l,mid,k);
	//else  ret+=sum[rs[y]]-sum[rs[x]],query(rs[x],rs[y],mid+1,r,k-sz[ls[y]]+sz[ls[x]]);
	if (sz[rs[y]]-sz[rs[x]]>=k) query(rs[x],rs[y],mid+1,r,k);
	else    ret+=sum[rs[y]]-sum[rs[x]],query(ls[x],ls[y],l,mid,k-sz[rs[y]]+sz[rs[x]]);
}
void solve1(int l,int r,int L,int R)//l,r status   L,R decision
{
	if (l>r)    return;
	int mid=(l+r)>>1;
	for (int i=L;i<=R;i++)
	{
		ret=0;query(root[st-1],root[i],1,c,st-i+mid);
		if (ret>f[mid]||!fd[mid])   f[mid]=ret,fd[mid]=i;
	}
	solve1(l,mid-1,L,fd[mid]);solve1(mid+1,r,fd[mid],R);
}
void solve2(int l,int r,int L,int R)
{
	if (l>r)    return;
	int mid=(l+r)>>1;
	for (int i=R;i>=L;i--)
	{
		ret=0;query(root[i-1],root[st-1],1,c,i-st+mid);
		if (ret>g[mid]||!gd[mid])   g[mid]=ret,gd[mid]=i;
	}
	solve2(l,mid-1,gd[mid],R);solve2(mid+1,r,L,gd[mid]);
}
void solve3(int l,int r,int L,int R)
{
	if (l>r)    return;
	int mid=(l+r)>>1;
	for (int i=L;i<=R;i++)
	{
		ret=0;query(root[st-1],root[i],1,c,((st-i)<<1)+mid);
		if (ret>f1[mid]||!f1d[mid]) f1[mid]=ret,f1d[mid]=i;
	}
	solve3(l,mid-1,L,f1d[mid]);solve3(mid+1,r,f1d[mid],R);
}
void solve4(int l,int r,int L,int R)
{
	if (l>r)    return;
	int mid=(l+r)>>1;
	for (int i=R;i>=L;i--)
	{
		ret=0;query(root[i-1],root[st-1],1,c,((i-st)<<1)+mid);
		if (ret>g1[mid]||!g1d[mid]) g1[mid]=ret,g1d[mid]=i;
	}
	solve4(l,mid-1,g1d[mid],R);solve4(mid+1,r,L,g1d[mid]);
}
int main()
{
	in(n);in(st);in(m);st++;
	for (int i=1;i<=n;i++)  in(b[i]),sta[i]=b[i];
	sort(sta+1,sta+n+1);c=unique(sta+1,sta+n+1)-sta-1;
	for (int i=1;i<=n;i++)  
		b[i]=lower_bound(sta+1,sta+c+1,b[i])-sta,
			ins(root[i-1],root[i],1,c,b[i],sta[b[i]]);
	solve1(1,m,st,min(n,st+m));solve2(1,m,max(1,st-m),n);
	solve3(1,m,st,min(n,st+(m>>1)));solve4(1,m,max(1,st-(m>>1)),n);
	for (int i=0;i<=m;i++)  ans=max(ans,g1[i]+f[m-i]);
	for (int i=0;i<=m;i++)  ans=max(ans,f1[i]+g[m-i]);
	cout<<ans<<endl;
}
