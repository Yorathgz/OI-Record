#include<iostream>
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
//type1
//from: http://www.cnblogs.com/lidaxin/p/4859338.html

int n,k,p;
int a[51],b[51],c[101];
int kk,cc;
int book;
int sum;

int main()
{
	n=read();k=read();p=read();
	for(int i=1;i<=n;i++)
	{
		kk=read();cc=read(); 
		a[kk]++;
		if(cc<=p)
		{
			for(int j=0;j<50;j++) b[j]=a[j];
			sum=sum+b[kk]-1;
		}
		else sum=sum+b[kk]; 
	}
	write(sum);
}
