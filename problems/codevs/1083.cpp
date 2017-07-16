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
//type10
//url: http://codevs.cn/problem/3134/

int main(){
	int maxx=1;
	bool first=0;
	int fz=2,fm=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		
		if(fm==maxx&&!first){
			first=1;
			maxx++;
			fm++;
		}
		else if(fz==maxx&&first){
			first=0;
			maxx++;
			fz++;
		}
		else if(first){
			fz++;
			fm--;
		}
		else{
			fz--;
			fm++;
		}
	}
	cout<<fz<<"/"<<fm;
	return 0;
}
