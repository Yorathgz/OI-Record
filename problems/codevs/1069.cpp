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

int p[40010];
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}
struct node{
	int a,b,c;
	node(int a,int b,int c):a(a),b(b),c(c){}
	bool operator<(const node&rhs)const{return c>rhs.c;}
};
vector<node>vec;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)p[i]=i;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		vec.push_back(node(a,b,c));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;;i++){
		node t(vec[i]);
		if(find(t.a)==find(t.b)){
			cout<<t.c;
			return 0;
		}
		p[find(t.a+n)]=find(t.b);
		p[find(t.b+n)]=find(t.a);
	}
}