#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define inf 0xffffff;
#define LL long long
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

char ch,B[1<<15],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
int aa;int F(){
	while(ch=getc(),ch<'0'||ch>'9');aa=ch-'0';
	while(ch=getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return aa;
}
char buf[1<<22],*O=buf,stk[30];int ts;
void Pr(int x){
	if(!x)*O++=48;else{
		for(ts=0;x;x/=10)stk[++ts]=x%10;
		for(;ts;*O++=48+stk[ts--]);
	}*O++='\n';
}
#define cmax(a,b) (a<b?a=b:1)
#define cmin(a,b) (a>b?a=b:1)
int rt,op,ans,D,tot,X0,X1,Y0,Y1,x,y;
#define fac 0.65
struct T{
	int d[2],s[2],x[2],y[2],w,sum,siz,ty;
	void setup(int xx,int yy,int v){
		s[0]=s[1]=0,x[0]=x[1]=d[0]=xx,y[0]=y[1]=d[1]=yy,sum=w=v,siz=1;
	}
	void clr(){
		x[0]=x[1]=d[0],y[0]=y[1]=d[1];
		s[0]=s[1]=0,sum=w,siz=1;
	}
}t[160010],tmp;
bool cmp(int a,int b){return t[a].d[D]<t[b].d[D];}
class KDTree{public:
#define ls t[now].s[0]
#define rs t[now].s[1]
	int po[160010],pt;
	void mt(int o,int s){
		t[o].sum+=t[s].sum,t[o].siz+=t[s].siz;
		cmin(t[o].x[0],t[s].x[0]),cmin(t[o].y[0],t[s].y[0]);
		cmax(t[o].x[1],t[s].x[1]),cmax(t[o].y[1],t[s].y[1]);
	}
	int bt(int l,int r,int d){
		int mid=l+r>>1,now;D=d;
		std::nth_element(po+l,po+mid,po+r+1,cmp);now=po[mid];
		t[now].clr();t[now].ty=d;
		if(l<mid)ls=bt(l,mid-1,d^1),mt(now,ls);
		if(mid<r)rs=bt(mid+1,r,d^1),mt(now,rs);
		return now;
	}
	void dfs(int now){
		po[++pt]=now;
		if(ls)dfs(ls);
		if(rs)dfs(rs);
	}
	int ins(int p,int now){
		if(!p)return t[now].ty=rand()&1,now;
		mt(p,now);D=t[p].ty;int&nx=t[p].s[t[now].d[D]>=t[p].d[D]];
		if(t[nx].siz>t[p].siz*fac)return po[pt=1]=now,dfs(p),p==rt?rt=bt(1,pt,t[p].ty):bt(1,pt,t[p].ty);
		nx=ins(nx,now);return p;
	}
#define check(a) (a.x[0]<=X1&&X0<=a.x[1]&&a.y[0]<=Y1&&Y0<=a.y[1])
	void query(int now){
		if(X0<=t[now].x[0]&&t[now].x[1]<=X1
				&&Y0<=t[now].y[0]&&t[now].y[1]<=Y1){
			ans+=t[now].sum;return;
		}
		if(X0<=t[now].d[0]&&t[now].d[0]<=X1
				&&Y0<=t[now].d[1]&&t[now].d[1]<=Y1)ans+=t[now].w;
		if(ls&&check(t[ls]))query(ls);
		if(rs&&check(t[rs]))query(rs);
	}
}kdt;
int main(){
	x=y=F()/2;t[tot=rt=1].setup(x,y,0);
	while(op=F(),op!=3)
		if(op==1){
			x=F()^ans,y=F()^ans,t[++tot].setup(x,y,F()^ans);
			kdt.ins(rt,tot);
		}
		else{
			X0=F()^ans,Y0=F()^ans,X1=F()^ans,Y1=F()^ans;
			ans=0,kdt.query(rt),Pr(ans);
		}*--O=0,puts(buf);
}
