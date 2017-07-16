#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define ll long long
using namespace std;

inline ll read()
{
	int x=0,f=1;char ch=0;
	while(ch!='-'&&(ch>'9'||ch<'0')) ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(ll x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
} 

/*************************************************************/
//type10
//url: http://codevs.cn/problem/3134/

#define N 21

ll Catalan(ll n)  
{  
	if(n <= 1)  
		return 1;
    
	ll *h = new ll[n+1];
	h[0] = h[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		h[i] = 0;
		for(int j = 0; j < i; j++)
			h[i] += (h[j] * h[i-1-j]);
	}
	ll result = h[n];
	delete [] h;
	return result;
}

int main()  
{
    ll n;n=read();
    write(Catalan(n));
    putchar(' ');
    write(n+1);
    return 0;
}
