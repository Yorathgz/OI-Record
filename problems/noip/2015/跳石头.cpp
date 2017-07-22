#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define ll long long
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
//type20, 

int L,n,m;
int d[50005];

bool can(int mid)
{
	int tot=0,last=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]-last<mid) tot++;
		else last=d[i];
	}
	if(tot>m) return false;
	return true; //if can move more
}

int main()
{
	cin>>L>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	d[++n]=L;
	int l=0,r=L,mid;
	while(l<r)
	{
		mid=(l+r)/2+1;
		if(can(mid)) l=mid; //move more
		else r=mid-1; //move less
	}
	cout<<l;
	return 0;
}
