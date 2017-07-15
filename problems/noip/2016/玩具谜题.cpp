#include<iostream>
using namespace std;

int n,m;
bool dir[100005];
string career[100005];

int getpeo(int dirc,int step,int peo)
{
	bool f;//0-&&1+
	if(dir[peo]&&dirc) f=0;
	else if(dir[peo]&&!dirc) f=1;
	else if(!dir[peo]&&dirc) f=1;
	else f=0;
	
	if(f)
	{
		if(peo+step>n)
		{
			step=n-step;
			dirc=!dirc;
			peo=getpeo(dirc,step,peo);
			return peo;
		}
		else peo+=step;
	}
	else
	{
		if(peo-step<1)
		{
			step=n-step;
			dirc=!dirc;
			peo=getpeo(dirc,step,peo);
			return peo;
		}
		else peo=peo-step;
	}
	return peo;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>dir[i]>>career[i];
	int dirc,step,peo=1;
	for(int i=1;i<=m;i++)
	{
		cin>>dirc>>step;
		peo=getpeo(dirc,step,peo);
		//cout<<"here::"<<peo<<endl;
	}
	cout<<career[peo]<<endl;
	return 0;
}