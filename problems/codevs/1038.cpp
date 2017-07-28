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
//type19, type20, 

double x1,x2,x3,a,b,c,d;
double f(double x){return a*x*x*x+b*x*x+c*x+d;}
double df(double x){return 3*a*x*x+2*b*x+c;}
double slove(double l,double r)
{
	double x,x0=(l+r)/2;
	while(abs(x0-x)>eps)
	  x=x0-f(x0)/df(x0),swap(x0,x);
	return x;
}
int main()
{
	cin>>a>>b>>c>>d;
	double p=(-b-sqrt(b*b-3*a*c))/(3*a);
	double q=(-b+sqrt(b*b-3*a*c))/(3*a);
	x1=slove(-100,p),x2=slove(p,q),x3=slove(q,100);
	printf("%.2lf %.2lf %.2lf",x1,x2,x3);
	return 0;
}