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

typedef long long ll;
using namespace std;
int hashuan[maxn],n,t[maxn][maxn],s[maxn][maxn];
double fx[maxn][maxn],dis[maxn];
bool vis[maxn];
inline bool spfa() {
	queue<int> q;
	memset(dis, -0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(hashuan, 0, sizeof(hashuan));
	dis[1]=0;
	vis[1]=true;
	q.push(1);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		vis[now]=false;
		f(to,1,n) {
			if(s[now][to]&& dis[to]<fx[now][to]+dis[now]) {
				dis[to]=fx[now][to]+dis[now];
				if(!vis[to]) {
					q.push(to);
					vis[to]=true;
					hashuan[to]++;
					if(hashuan[to]>n)
						return true;
				}
			}
		}
	}
	if(dis[n]>0)
		return true;
	else
		return false;
}
inline bool check(double x) {
	memset(fx,0,sizeof(fx));
	f(i,1,n)
	f(j,1,n)
	fx[i][j]=s[i][j]-x*t[i][j];
	if(spfa())
		return true;
	else
		return false;
}
int main() {
	cin>>n;
	f(i,1,n)
	f(j,1,n)
	scanf("%d",&s[i][j]);
	f(i,1,n)
	f(j,1,n)
	scanf("%d",&t[i][j]);
	double l=0,r=100000;
	double jindu=0.0001;
	double midv;
	while(r-l>jindu) {
		midv=(l+r)/2;
		if(check(midv))
			l=midv;
		else
			r=midv;
	}
	printf("%.3lf",l);
	return 0;
}