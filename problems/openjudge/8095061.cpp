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
//type19

int a[9],t=1;
int m(int y,int z){
	for(int k=1;k<y;k++)
	if(a[y-k]==z||a[y-k]==z+k||a[y-k]==z-k)
	return 0;
	return 1;
}
void s(int x){
	int i,l;
	if(x==9){
		printf("No. %d\n",t);
		for(i=1;i<=8;i++){
			for(l=1;l<=8;l++)
			if(a[l]==i)
			printf("1 ");
			else printf("0 ");
			printf("\n");
		}
		t++;
		return;
	}
	for(i=1;i<=8;i++)
	if(m(x,i)>0){
		a[x]=i;
		s(x+1);
	}
}
int main(){
	s(1);
}
