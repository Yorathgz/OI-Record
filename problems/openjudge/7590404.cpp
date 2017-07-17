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

int maxn=10000,maxstep=1000,result;
int R[10001][4],Ro[4],Rway[1000];

bool find(int j)
{
	int m=1;
	bool cc=true;
	while (m<j && cc) 
	{
		if (R[m][1]==R[j][1] && R[m][2]==R[j][2] && R[m][3]==R[j][3])
			cc=false;
		m++;
	}
	return cc;
}

bool pd(int w)
{
	if (R[w][1]==result || R[w][2]==result || R[w][3]==result)
		return true;
	else return false;
}

void outresult(int j)
{
	int i,k=0,z;
	z=j;
	while (z>0) 
	{
		k++;
		Rway[k]=z;
		z=R[z][0];
	}
	printf("%d\n",k);   
	for (i=k; i>0; i--) 
	{
		z=Rway[i];
		printf("%d %d %d\n",R[z][1],R[z][2],R[z][3]);
	}
	return;
}

void split()
{
	if (pd(1)) 
	{
		outresult(1);
		return;
	}
	if (result>Ro[1])
	{
		printf("No find");
		return;
	}
	int i=1,j=2,k,s,tem;
	while (i<j && j<maxn) 
	{
		for (k=1; k<=3; k++) 
			if (R[i][k]<Ro[k]) 
				for (s=1; s<=3; s++) 
					if (s!=k && R[i][s]>0) 
					{
						R[j][1]=R[i][1];  R[j][2]=R[i][2];  R[j][3]=R[i][3];
						tem=Ro[k]-R[i][k];
						if (tem>R[i][s]) 
						{
							R[j][k]=R[j][s]+R[j][k];
							R[j][s]=0;
						}	   
						else
						{
							R[j][k]=Ro[k];
							R[j][s]=R[j][s]-tem;
						}
						if (find(j)) 
						{
							R[j][0]=i;
							if (pd(j)) 
							{
								outresult(j);
								return;
							} 
							else j++;
						}
					}
		i++; 
	} 
	printf("No find");
	return;
}

int main()
{
	scanf("%d %d %d %d",&Ro[1],&Ro[2],&Ro[3],&result);
	R[1][1]=Ro[1];  R[1][2]=0;  R[1][3]=0;
	split();
	return 0;
}
