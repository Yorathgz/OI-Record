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

int main() 
{ 
	int n; 
	cin>>n; 
	int a[101]={0}; 
	for(int i=n;i>=0;i--) 
		cin>>a[i]; 
	for(int i=n;i>=0;i--){ 
		if(a[i]>0&&i!=n)cout<<'+'; 
		if(a[i]!=0){ 
			if((a[i]!=1||i==0)&&a[i]!=-1)cout<<a[i]; 
			if(a[i]==-1){cout<<'-';if(i==0)cout<<1;} 
			if(i>0)cout<<'x'; 
			if(i>1)cout<<'^'<<i; 
		} 
	} 
	return 0; 
}
