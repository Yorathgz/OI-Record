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
//type3,

using namespace std;
int step;
int f[1200][101];

int mx(int i,int j) 
{ 
	int m=0; 
	if(f[i+1][j-2]>m&&j-2>0){m=f[i+1][j-2];step=-2;} 
	if(f[i+1][j-1]>m&&j-1>0){m=f[i+1][j-1];step=-1;} 
	if(f[i+1][j]>m){m=f[i+1][j];step=0;} 
	if(f[i+1][j+1]>m){m=f[i+1][j+1];step=1;} 
	if(f[i+1][j+2]>m){m=f[i+1][j+2];step=2;} 
	return m; 
}

int main() 
{ 
	int c[10001],x[10001],t[10001],v[10001]; 
	int n=1,h,w; 
	int i,j,k; 
	int m=0,time=0; 
	cin>>w>>h; 
	h--; 
	while(cin>>t[n]>>x[n]>>v[n]>>c[n]){ 
		if(h%v[n]==0){ 
			t[n]+=h/v[n]; 
			time=max(time,t[n]); 
			n++; 
		} 
	} 
	memset(f,0,sizeof(f)); 
	for(i=1;i<=n;i++)f[t[i]][x[i]]+=c[i]; 
	for(i=time-1;i>=0;i--) 
		for(j=w;j>0;j--) 
			f[i][j]+=mx(i,j); 
	cout<<f[0][w/2+1]<<endl; 
	for(i=0,j=w/2+1;;i++){ 
		if(mx(i,j)==0)break; 
		j+=step; 
		cout<<step<<endl; 
	} 
	return 0; 
}
