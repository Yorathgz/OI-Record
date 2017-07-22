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

bool p[201][201];  
main()  
{   
	short n2,n,i,j,sumx,sumy,k;   
	double l[100],d[100],r[100],u[100],y[200],x[200],ans;   
	scanf("%hd",&n);   
	while(n)  
	{   
		ans=0;   
		memset(p,0,sizeof(p));   
		for(i=-1;++i<n;)  
		{   
			scanf("%lf%lf%lf%lf",&l[i],&d[i],&r[i],&u[i]);   
			y[i]=d[i];   
			y[i+n]=u[i];   
			x[i]=l[i];  
			x[i+n]=r[i];   
		}   
		n2=2*n;   
		sort(y,y+n2);   
		sort(x,x+n2);   
		sumx=unique(x,x+n2)-x,sumy=unique(y,y+n2)-y;   
		for(k=-1;++k<n;)  
		{   
			l[k]=lower_bound(x,x+sumx,l[k])-x;   
			r[k]=lower_bound(x,x+sumx,r[k])-x;   
			u[k]=lower_bound(y,y+sumy,u[k])-y;   
			d[k]=lower_bound(y,y+sumy,d[k])-y;   
			for(i=r[k];i>l[k];--i)  
				for(j=u[k];j>d[k];--j)   
					p[i][j]=1;  
		}   
		for(i=0;++i<sumx;)   
			for(j=0;++j<sumy;)   
				if(p[i][j])   
					ans+=(x[i]-x[i-1])*(y[j]-y[j-1]);   
		printf("%.2lf\n",ans);   
		scanf("%hd",&n);   
	}  
}  
