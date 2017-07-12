#include<cstdio> 
#define i64 long long
#define mod 20100403
#define FOR1(i,n) for(int i=1;i<=n;i++)

i64 n,m;

inline i64 read()
{
	i64 x=0,f=1;char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void write(i64 x)
{
	if(x<0)putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

i64 exGcd(i64 a,i64 b,i64 &x,i64 &y)
{
    if(b==0)
    {
        x=1; y=0;
        return a;
    }
    i64 temp=exGcd(b,a%b,x,y);
    i64 t=x;
    x=y;
    y=t-a/b*y;
    return temp;
}


i64 reverse(i64 a,i64 b)
{
    i64 x,y;
    exGcd(a,b,x,y);
    return (x%b+b)%b;
}


i64 get(i64 n)
{
    i64 ans=1,i;
    FOR1(i,n) ans=ans*i%mod;
    return ans;
}


i64 cal(i64 n,i64 m)
{
    i64 x=get(n),y=get(m),z=get(n-m);
    return x*reverse(y,mod)%mod*reverse(z,mod)%mod;
}


int main()
{
    int n,m;
    n=read();m=read();
    i64 ans=cal(n+m,n)-cal(n+m,n+1);
    ans=(ans%mod+mod)%mod;
    write(ans);
    return 0;
}