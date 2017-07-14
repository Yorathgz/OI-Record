#include<iostream>
#include<cstring>
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

int l,r,sum;

int main()
{
	l=read();r=read();
	while(l<=r)
	{
		if(l%10==2) sum++;
		if(l%10%10==2) sum++;
		if(l%10%10%10==2) sum++;
		if(l%10%10%10%10==2) sum++;
		l++;
	}
	write(sum);
	return 0;
}
