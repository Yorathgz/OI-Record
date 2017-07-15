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
//type5
//url: http://hzwer.com/70.html

int n,r,d;
int v;
float s[1001];
bool dl[1001]={0};
bool pd[1001][1001];
struct f{
	int x,y,h;
}f[1001];
float work(int a,int b)
{
    if(a==b)return 0;
    float s=sqrt((f[a].x-f[b].x)*(f[a].x-f[b].x)+(f[a].y-f[b].y)*(f[a].y-f[b].y));
    float h1=abs(f[a].h-f[b].h);
    if(s<=r&&h1<=d) return sqrt(s*s+h1*h1);
    else return -1;
}
void search()
{
    int t=0,w=1;
    int d[5000]={1};
    dl[1]=1;
    s[1]=0;
    while(t<w)
    {
        for(int i=1;i<=n;i++)
        {
            if(pd[d[t]][i]==1&&s[d[t]]+work(d[t],i)<s[i])
            {
                s[i]=s[d[t]]+work(d[t],i);
                if(dl[i]==0)
                {
					d[w]=i;
					dl[i]=1;
					w++;
                }
            }
        }
        dl[d[t]]=0;
        t++;
    }
}
int main()
{
    cin>>n>>r>>d>>v;
    for(int i=1;i<=n;i++)
		cin>>f[i].x>>f[i].y>>f[i].h;
    for(int i=1;i<=n;i++)
    {
		s[i]=9999;
		for(int j=1;j<=n;j++)
		{
            if(work(i,j)==-1){pd[i][j]=0;}
            else pd[i][j]=1;
		}
	}
	search();
	if(s[n]!=9999)printf("%.3f",s[n]/v);
	else cout<<"No Solution";
    return 0;
}
