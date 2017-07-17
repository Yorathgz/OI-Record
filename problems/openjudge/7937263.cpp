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
//type14,

int maxn=50000,result=0,way[5000];
bool rep[87654322];
struct node{
	int num,father,abc; 
} s[50001];

int aa(int x)
{
	int y=0;
	for (int i=0; i<8; i++)
	{
		y=y*10+x%10;
		x=x/10;
	}
	return y;
}

int bb(int x)
{
	int y,w;
	w=x/10000;
	y=w%10*10000000+w/10*10000;
	w=x%10000;
	y=y+w%1000*10+w/1000;
	return y;
}

int cc(int x)
{
	int y,w,cs[8];
	w=x;
	for (int i=7; i>=0; i--)
	{
		cs[i]=w%10;
		w=w/10;
	}
	y=cs[0]*10000000+cs[6]*1000000+cs[1]*100000+cs[3]*10000;
	y=y+cs[4]*1000+cs[2]*100+cs[5]*10+cs[7];
	return y;
}

void outresult(int x) 
{
	int k=0,i,z;
	z=x;
	while (z>0)
	{ 
		k++;
		way[k]=z;
		z=s[z].father;
	}
	printf("%d\n",k-1);
	for (i=k-1; i>0; i--) 
		printf("%c",s[way[i]].abc+65);
	return;
}

void bfs()
{
	if (s[1].num==result)
	{
		printf("0");
		return;
	}
	int i=1,j=2,k,p;
	while (i<j && j<maxn)
	{
		for (k=0; k<3; k++)
		{
			if (k==0) p=aa(s[i].num);
			else
				if (k==1) p=bb(s[i].num);
				else
					if (k==2) p=cc(s[i].num);
			if (rep[p]==0)
			{
				s[j].num=p; s[j].father=i; s[j].abc=k; 
				rep[p]=1;
				if (p==result)
				{ 
					outresult(j);
					return;
				}
				j++;
			}
		}
		i++;
	}
	return;
}

int main()
{
	int i,j;
	for (i=0; i<8; i++)
	{
		scanf("%d",&j);
		result=result*10+j;
	}
	s[1].num=12345678; s[1].father=0;
	memset(rep,0,sizeof(rep));
	rep[12345678]=1;
	bfs();
	return 0;
}
