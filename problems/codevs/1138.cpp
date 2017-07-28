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

#define MAX 200005
struct L
{
    long long left,right;
}qujian[MAX];
long long n,m,s,wx,v[MAX],w[MAX],i,j,x[MAX],xx[MAX],now;
long long abs(long long x)
{
    return x>0 ? x : -x;
} 
void search(long long l,long long r)
{
    if(l==r)
        return;
    wx=(l+r)/2;//wx表示当前设定的W 
    memset(x,0,sizeof(x));
    memset(xx,0,sizeof(xx));
    for(i=1;i<=n;i++)
    {
        x[i]=x[i-1];
        xx[i]=xx[i-1];
        if(w[i]>=wx)
        {
            x[i]++;//x数组前缀保存到目前为止符合要求的矿石数 
            xx[i]+=v[i];//xx数组表示到目前为止符合要求的矿石的价值和 
        }
    }
    long long y=0;
    for(i=1;i<=m;i++)
    {
        y+=(x[qujian[i].right]-x[qujian[i].left-1])*(xx[qujian[i].right]-xx[qujian[i].left-1]);//计算区间y的值 
    }
    if(abs(s-y)<abs(s-now))
    now=y;//如果当前计算出的y与s的绝对值比上一次的y更小就更新y 
    if(s>y)
    search(l,wx);//可以证明当y值比s小时，w的值应该在左区间 
    if(s==y)
    {
        now=s;
        return;
    }
    if(s<y)
    search(wx+1,r);//可以证明当y值比s大时，w的值应该在右区间 
}

int main()
{
    scanf("%lld%lld%lld",&n,&m,&s);
    for(i=1;i<=n;i++)
        scanf("%lld%lld",&w[i],&v[i]);
    for(i=1;i<=m;i++)
        scanf("%lld%lld",&qujian[i].left,&qujian[i].right);
    search(1,100000);
    printf("%lld",abs(s-now));
    return 0;
}