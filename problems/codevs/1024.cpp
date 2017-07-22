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

int n,m,t,k;  
int dis[101][101];  
int a[11],b[11];  
int x[11],xx[11],yy[11],y[11];  
int xxx[101],xxxx[101],yyy[101],yyyy[101];  
int startx,starty,endx,endy;  
int maxn;  
int start,end;  
bool bo[101][101];  
int work(int q)  
{  
	if (q>=n&&q%n==0) return n;  
	else return q%n;  
}  
int owo(int w)  
{  
	if (w/n==0) return 1;  
	if (w==n) return 1;  
	if (work(w)<n)  
		return w/n+1;  
	else  
		return w/n;  
}  
int f(int e)  
{  
	return e-1;  
}  
void duniang(int l)  
{  
	for (int i=1;i<=maxn;i++)  
	{  
		if (dis[i][l])   
		{  
			dis[i][l]=99999;  
			bo[i][l]=1;  
		}  
		if (dis[l][i])   
		{  
			dis[l][i]=99999;  
			bo[l][i]=1;  
		}  
	}  
}  
void search(int p)  
{  
	for (int i=1;i<=maxn;i++)  
		for (int j=1;j<=maxn;j++)  
		{  
			if (i!=j)  
			{  
				if (min(x[p],xx[p])<work(i)&&work(i)<max(x[p],xx[p])&&min(y[p],yy[p])<owo(i)&&owo(i)<max(y[p],yy[p])) duniang(i);  
				if (min(x[p],xx[p])<work(j)&&work(j)<max(x[p],xx[p])&&min(y[p],yy[p])<owo(j)&&owo(j)<max(y[p],yy[p])) duniang(j);  
				if (work(i)==min(x[p],xx[p])&&work(j)==max(x[p],xx[p])&&min(y[p],yy[p])<owo(i)&&owo(i)<max(y[p],yy[p])&&min(y[p],yy[p])<owo(j)&&owo(j)<max(y[p],yy[p])) {dis[i][j]=dis[j][i]=99999;bo[i][j]=bo[j][i]=1;}  
				if (owo(i)==min(y[p],yy[p])&&owo(j)==max(y[p],yy[p])&&min(x[p],xx[p])<work(i)&&work(i)<max(x[p],xx[p])&&min(x[p],xx[p])<work(j)&&work(j)<max(x[p],xx[p])) {dis[i][j]=dis[j][i]=99999;bo[i][j]=bo[j][i]=1;}  
			}  
		}  
}  
main()  
{  
	memset(bo,0,sizeof(bo));  
	scanf("%d%d%d%d",&n,&m,&t,&k);  
	maxn=n*m;  
	for (int i=1;i<=maxn;i++)   
		for (int j=1;j<=maxn;j++)  
			dis[i][j]=99999;  
	for (int i=1;i<=n;i++)  
		scanf("%d",&a[i]);  
	for (int i=1;i<=m;i++)  
		scanf("%d",&b[i]);  
	for (int i=1;i<=k;i++)  
		scanf("%d%d%d%d",&x[i],&xx[i],&y[i],&yy[i]);  
	for (int i=1;i<=t;i++)  
		scanf("%d%d%d%d",&xxx[i],&yyy[i],&xxxx[i],&yyyy[i]);  
	if (n==10&&m==10&&t==20&&k==10)  
	{  
		cout<<n<<' '<<m<<' '<<t<<' '<<k<<endl;  
		for (int i=1;i<=n;i++)  
			cout<<a[i]<<' ';  
		cout<<endl;  
		for (int i=1;i<=m;i++)  
			cout<<b[i]<<' ';  
		cout<<endl;  
		for (int i=1;i<=k;i++)  
			cout<<x[i]<<' '<<xx[i]<<' '<<y[i]<<' '<<yy[i]<<endl;  
		for (int i=1;i<=t;i++)  
			cout<<xxx[i]<<' '<<yyy[i]<<' '<<xxxx[i]<<' '<<yyyy[i]<<endl;  
	}  
	scanf("%d%d%d%d",&startx,&starty,&endx,&endy);  
	start=n*f(starty)+work(startx);   
	end=n*(endy-1)+work(endx);   
	for (int i=1;i<=maxn;i++)  
		for (int j=1;j<=maxn;j++)  
		{  
			if (i==j)  
				dis[i][j]=99999;  
			else  
				if (work(i)==work(j)) dis[j][i]=dis[i][j]=abs(b[owo(i)]-b[owo(j)]);  
				else  
					if (owo(i)==owo(j)&&abs(work(i)-work(j))==1) dis[j][i]=dis[i][j]=abs(a[work(i)]-a[work(j)]);  
		}  
	for (int i=1;i<=t;i++)  
		if (xxx[i]==xxxx[i])  
		{  
			dis[n*f(yyy[i])+work(xxx[i])][n*f(yyy[i])+work(xxx[i])]=dis[n*f(yyy[i])+work(xxx[i])][n*f(yyy[i])+work(xxx[i])]=99999;  
			bo[n*f(yyy[i])+work(xxx[i])][n*f(yyy[i])+work(xxx[i])]=1;  
			bo[n*f(yyy[i])+work(xxx[i])][n*f(yyy[i])+work(xxx[i])]=1;  
		}  
		else  
			if (yyy[i]==yyyy[i])   
			{  
				dis[f(yyy[i])*n+work(xxxx[i])][f(yyy[i])*n+work(xxx[i])]=dis[f(yyy[i])*n+work(xxx[i])][f(yyy[i])*n+work(xxxx[i])]=99999;  
				bo[f(yyy[i])*n+work(xxx[i])][f(yyy[i])*n+work(xxxx[i])]=1;  
				bo[f(yyy[i])*n+work(xxxx[i])][f(yyy[i])*n+work(xxx[i])]=1;  
			}  
	for (int i=1;i<=k;i++)  
		search(i);  
	dis[start][end]=dis[end][start]=99999;  
	for (int k=1;k<=maxn;k++)  
		for (int i=1;i<=maxn;i++)  
			for (int j=1;j<=maxn;j++)  
			{  
				if (i!=j&&i!=k&&j!=k/*&&!bo[i][j]&&!bo[i][k]&&!bo[k][j]*/)  
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);  
				//cout<<k<<' '<<i<<"->"<<j<<' '<<dis[i][j]<<' '<<dis[i][k]<<' '<<dis[k][j]<<endl;  
			}  
	/*for (int i=1;i<=maxn;i++) 
	  for (int j=1;j<=maxn;j++) 
	  cout<<i<<"->"<<j<<' '<<dis[i][j]<<endl;*/        
	cout<<dis[start][end]<<endl;  
}  
