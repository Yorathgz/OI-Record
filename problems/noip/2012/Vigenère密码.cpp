#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff
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
//type1, type6

char A[1005],a[1005],B[1005];
int main(){
    scanf("%s %s",a,B);
    int n=strlen(a),m=strlen(B);
    for(int i=0;i<m;i++)
	{
        int ok=0;
        A[i]=a[i%n];
        if(A[i]<='Z')A[i]+=32;
        if(B[i]<='Z')B[i]+=32,ok=32;
        int k=B[i]-A[i]+27;
        if(k>=1&&k<=26)printf("%c",k-ok+'a'-1);
        else printf("%c",k-ok+'a'-27);
    }
    return 0;
}
