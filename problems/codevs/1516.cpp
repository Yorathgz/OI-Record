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
//type19, type20, 

long long n,L,R;
long long a[maxn];
long long presum[maxn];
long long gcd(long long a,long long b)
{
	return b==0? a: gcd(b,a%b);
}
long long gui1[maxn],gui2[maxn];
long long b1[maxn],b2[maxn];
long long anti,anti2;
void merge_sort1(long long l,long long r)
{
	if (l==r) return;
	long long mid=(l+r)/2;
	merge_sort1(l,mid);
	merge_sort1(mid+1,r);
	long long lef=l,rig=mid+1;
	for (long long i=l;i<=r;i++)
	{
		long long tian;
		if (lef==mid+1)	tian=2;
		else
		if (rig==r+1) tian=1;
		else
		if (gui1[lef]<gui1[rig]) tian=1;
		else tian=2;
		
		if (tian==1)
			b1[i]=gui1[lef],lef++,anti=anti+(rig-mid-1);
		else
			b1[i]=gui1[rig],rig++;
	}
	for (long long i=l;i<=r;i++)
		gui1[i]=b1[i];
	return;
}

void merge_sort2(long long l,long long r)
{
	if (l==r) return;
	long long mid=(l+r)/2;
	merge_sort2(l,mid);
	merge_sort2(mid+1,r);
	long long lef=l,rig=mid+1;
	for (long long i=l;i<=r;i++)
	{
		long long tian;
		if (lef==mid+1)	tian=2;
		else
		if (rig==r+1) tian=1;
		else
		if (gui2[lef]<=gui2[rig]) tian=1;
		else tian=2;
		
		if (tian==1)
			b2[i]=gui2[lef],lef++,anti2=anti2+(rig-mid-1);
		else
			b2[i]=gui2[rig],rig++;
	}
	for (long long i=l;i<=r;i++)
		gui2[i]=b2[i];
	return;
}
int main()
{
	cin>>n>>L>>R;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
		presum[i]=presum[i-1]+a[i]; 
	}
	
	for(long long i=1;i<=n;i++)
	{
		gui1[i]=L*i-presum[i];
		gui2[i]=R*i-presum[i];
	}

	merge_sort1(0,n);
	
	merge_sort2(0,n);
	
	long long chu=n*(n+1)/2;
	
	if(anti-anti2==0)
	{
	 	cout<<"0"<<endl;
	 	return 0;
	}
	if(anti-anti2==chu) 
	{
		cout<<"1"<<endl;
		return 0;
	}
	else 
	{
		long long g=gcd(anti-anti2,chu);
		cout<<(anti-anti2)/g<<"/"<<chu/g<<endl;
	}
}