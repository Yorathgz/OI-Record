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
//type12
//url: http://codevs.cn/problem/2879/

int main(){
	ios::sync_with_stdio(0);
	int n,i;
	int tree[101];
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>tree[i];
	for(i=n/2;i>=1;i--)
	if((i*2<=n&&tree[i]<=tree[i*2])||(i*2+1<=n&&tree[i]<=tree[i*2+1])){
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}