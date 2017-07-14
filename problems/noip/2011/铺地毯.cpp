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

struct data{
	int a,b,g,k;
}Data[10001];

int n,xi,yi;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		cin>>Data[i].a>>Data[i].b>>Data[i].g>>Data[i].k;
	xi=read();yi=read();
	for(int i=n;i>0;i--)
		if(Data[i].a<=xi&&xi<=Data[i].a+Data[i].g&&Data[i].b<=yi&&yi<=Data[i].b+Data[i].k)
		{
			cout<<i;
			return 0;
		}
	cout<<-1;
	return 0;
}