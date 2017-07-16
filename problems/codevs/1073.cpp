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
//type13
//url: http://codevs.cn/problem/1073/

int pre[10000];

int find(int x){
	int r=x;
	while(pre[r]!=r)
	r=pre[r];
	
	int i=x,j;
	while(i!=r){
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	
	return r;
}

void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	pre[fx]=fy;
}

int main(){
	int n,m,p,i,a,b;
	cin>>n>>m>>p;
	for(i=0;i<n;i++)
	pre[i]=i;
	for(i=0;i<m;i++){
		cin>>a>>b;
		join(a,b);
	}
	for(i=0;i<p;i++){
		cin>>a>>b;
		if(find(a)==find(b))
		cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}