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
//type20, 

double f(double x)
{
	return x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
}
double binary_search(double low,double high)
{
	double mid=(high-low)/2+low;
	if (high-mid<0.000001) return high;
	return f(mid)>0?binary_search(mid+0.000001,high):binary_search(low,mid);
}
int main()
{
	double x;
	printf("%.6lf",binary_search(1.500000,2.400000));//输出六位
}