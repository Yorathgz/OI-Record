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
//type1,

struct data{
	int num,sc;
}a[5005];
int n,m,r;
bool cmp(data a,data b)
{
	if((a.sc>b.sc)||(a.sc==b.sc&&a.num<b.num))return 1;
	else return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].sc;
	sort(a+1,a+n+1,cmp);
	int s=a[int(m*1.5)].sc;
	for(int i=1;i<=n;i++)
		if(a[i].sc>=s)r++;
	cout<<s<<' '<<r<<endl;
	for(int i=1;i<=r;i++)
		cout<<a[i].num<<' '<<a[i].sc<<endl;
	return 0;
}
