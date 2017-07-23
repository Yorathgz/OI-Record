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

	template <class classname>
inline void in(classname &x)
{
	char ch=getchar();x=0;
	while (!GET)    ch=getchar();
	while (GET) x=x*10+ch-'0',ch=getchar();
}
int n;
int a[MAXN];
double f[2][MAXN];
struct node
{
	int l,r,x;
	node()  {}
	node(int _l,int _r,int _x)  {   l=_l;r=_r;x=_x; }
}q[MAXN];
inline double calc(int j,int i) {   return a[j]+sqrt(abs(j-i))-a[i];    }
inline int find(node d,int x)
{
	int l=d.l,r=d.r,mid=(l+r)>>1;
	for (;l<=r;mid=(l+r)>>1)   if (calc(x,mid)<calc(d.x,mid))   l=mid+1;    else    r=mid-1;
	return l;
}
void solve(int id)
{
	for (int i=1,h=1,t=0,j;i<=n;i++)
	{
		if (h<=t&&++q[h].l>q[h].r)    h++;f[id][i]=calc(q[h].x,i);
		if (h>t||calc(i,n)>calc(q[t].x,n))
		{
			while (h<=t&&calc(i,q[t].l)>calc(q[t].x,q[t].l))  t--;
			if (h<=t)    j=find(q[t],i),q[t].r=j-1,q[++t]=node(j,n,i);
			else    q[++t]=node(i,n,i);
		}
	}
}
int main()
{
	in(n);
	for (int i=1;i<=n;i++)   in(a[i]);
	solve(0);
	for (int i=1;i<=(n>>1);i++)    swap(a[i],a[n-i+1]);
	solve(1);
	for (int i=1;i<=n;i++)   printf("%d\n",max(0,(int)ceil(max(f[0][i],f[1][n-i+1]))));
}

