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
//type3, type4

int main()
{
	int n;
	cin>>n;
	int x,i,j,k,pd=0;
	int a[101]={0};
	for(i=1,k=0;i<=n;i++)
	{
		cin>>x;
		for(j=0;j<k;j++)
		{
			if(a[j]==x){pd=1;break;}
		}
		if(pd==0)
		{
			a[k]=x;
			k++;
		}
		else pd=0;
	}
	sort(a,a+k);
	cout<<k<<endl;
	for(i=0;i<k;i++)
	{
		cout<<a[i];
		if(i!=k-1)cout<<' ';
	}
	//system("pause");
	return 0;
}
