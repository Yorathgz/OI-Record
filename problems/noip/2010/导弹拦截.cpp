#include<iostream>
#include<cstdlib>
#include<algorithm>
#define inf 0xffffff
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
//type2

struct point{
	int x,y,s1,s2;
}p[100001];

bool cmp(point p1,point p2)
{
	return p1.s1<p2.s1;
}

int x1,y1,x2,y2;
int n;
int mn=inf;

int main()
{
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		p[i].s1=(p[i].x-x1)*(p[i].x-x1)+(p[i].y-y1)*(p[i].y-y1);
		p[i].s2=(p[i].x-x2)*(p[i].x-x2)+(p[i].y-y2)*(p[i].y-y2);
	}
	sort(p+1,p+1+n,cmp);
	int rb=0;
	for(int i=n;i;i--)
	{
		rb=max(rb,p[i+1].s2);
		mn=min(mn,p[i].s1+rb);
	}
	cout<<mn;
	return 0;
}
