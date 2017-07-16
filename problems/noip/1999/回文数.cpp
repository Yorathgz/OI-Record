#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
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
//type1, type9
//url: http://hzwer.com/122.html

struct bign 
{ 
    int len,num[1001]; 
    bign() 
    { 
        len=0; 
        memset(num,0,sizeof(num)); 
    } 
}; 
int getnum(char ch) 
{ 
    if(ch>='0'&&ch<='9')return (int)ch-'0'; 
    if(ch>='A'&&ch<='Z')return (int)ch-'A'+10; 
} 
bign pplus(bign a,bign b,int k) 
{ 
    int j=0;bign c; 
    for(int i=0;j||i<max(a.len,b.len);i++) 
    { 
        if(i<a.len)j+=a.num[i]; 
        if(i<b.len)j+=b.num[i]; 
        c.num[c.len++]=j%k; 
        j/=k; 
    } 
    return c; 
} 
bign reverse(bign a) 
{ 
    int i=a.len-1,j; 
    bign b; 
    for(j=0;j<=a.len-1;j++) 
        if(a.num[j]!=0)break; 
    for(i;i>=j;i--) 
        b.num[b.len++]=a.num[i]; 
    return b; 
} 
bool dengyu(bign a,bign b) 
{ 
    if(a.len!=b.len)return false; 
    for(int i=0;i<=a.len-1;i++) 
        if(a.num[i]!=b.num[i])return false; 
    return true; 
} 
string m; 
int n,step=0; 
bign sum; 
int main() 
{ 
    cin>>n>>m; 
    for(int i=m.length()-1;i>=0;i--) 
        sum.num[sum.len++]=getnum(m[i]); 
    while(!dengyu(sum,reverse(sum))) 
    { 
        sum=pplus(sum,reverse(sum),n); 
        if(++step>=30) 
        { 
            cout<<"Impossible!"<<endl; 
            return 0; 
        } 
    } 
    cout<<"STEP="<<step<<endl; 
    return 0; 
}
