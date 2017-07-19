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
//type1,

#include<iostream>    
using namespace std; 
int main() 
{ 
	char ch;
	int sa11[10000]={0},sb11[10000]={0},sa21[10000]={0},sb21[10000]={0}; 
	int t11=1,t21=1,sca11=0,scb11=0,sca21=0,scb21=0;
	int first=0;
	while(cin>>ch) 
	{ 
		if (ch=='E')  
		{ 
			if(first==0) {cout<<"0:0"<<endl<<endl<<"0:0";return 0;} 
			sa11[t11]=sca11;sb11[t11]=scb11;sa21[t21]=sca21;sb21[t21]=scb21;t11++;t21++;break; 
		} 
		first++; 
		if (ch=='W'){sca11++;sca21++;} 
		if (ch=='L'){scb11++;scb21++;} 
		if (sca11>=11&&sca11-scb11>=2) {sa11[t11]=sca11;sb11[t11]=scb11;t11++;sca11=0;scb11=0;} 
		if (scb11>=11&&scb11-sca11>=2) {sa11[t11]=sca11;sb11[t11]=scb11;t11++;sca11=0;scb11=0;} 
		if (sca21>=21&&sca21-scb21>=2) {sa21[t21]=sca21;sb21[t21]=scb21;t21++;sca21=0;scb21=0;} 
		if (scb21>=21&&scb21-sca21>=2) {sa21[t21]=sca21;sb21[t21]=scb21;t21++;sca21=0;scb21=0;} 
	} 

	for (int i=1;i<t11;i++) 
	{ 
		cout<<sa11[i]<<':'<<sb11[i]<<endl; 
	} 
	cout<<endl; 
	for (int i=1;i<t21;i++) 
	{ 
		cout<<sa21[i]<<':'<<sb21[i]<<endl; 
	} 
	return 0; 
}
