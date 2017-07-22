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
//type19, 

int c;  
int main()  
{  
	scanf("%d",&c);  
	for (int i=0;i<c;i++)  
	{  
		int m,n;  
		scanf("%d%d",&m,&n);  
		if (m<n)  
		{  
			int t=m;  
			m=n;  
			n=t;  
		}  
		int f=1;  
		while (m/n==1&&m%n)  
		{  
			int t=m%n;  
			m=n;  
			n=t;  
			f=-f;  
		}  
		if (f==1) cout<<"Stan wins"<<endl;  
		else cout<<"Ollie wins"<<endl;  
	}  
	system("pause");  
}  

