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

int a[150000000],b,i,s=1;
void qsort(int l,int r)
{
	int i,j,mid,p;
	i=l;j=r;
	mid=a[(l+r)/2];
	do
	{
		while(a[i]mid)j–;
		if(i<=j)
		{
			p=a[i];a[i]=a[j];a[j]=p;
			i++;j–;
		}
	}
	while(i<=j);
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(1,n);
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i+1]) s++;
		else {cout<<a[i]<<' '<<s<<endl;s=1;}
	}
	return 0;
}
