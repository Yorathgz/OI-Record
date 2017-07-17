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

int c,n;
int tree[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin>>c;
	while(c--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>tree[i][j];
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=i;j++)
				if(tree[i+1][j]>tree[i+1][j+1])
					tree[i][j]+=tree[i+1][j];
				else
					tree[i][j]+=tree[i+1][j+1];
		cout<<tree[1][1]<<endl;
	}
	return 0;
}