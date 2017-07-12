#include<iostream>
using namespace std;
//普通dijkstra算法：适用单元最短路，时间复杂度为O(n^2) 
int inf=999999999;

int main(){
	ios::sync_with_stdio(0);
	int e[101][101],book[101]={0},dis[101],i,j,k,n,m,a,b,c,min;
	cin>>n>>m;
	//初始化路径长度数组和记录确定点的数组 
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i==j) e[i][j]=0;
	else e[i][j]=inf;
	book[1]=1;
	//读入路径长 
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	//初始化估计值数组 
	for(i=1;i<=n;i++)
	dis[i]=e[1][i];
	//dijkstra算法核心语句 
	for(i=1;i<n;i++){
		min=inf;
		//以未确定点中估计路径值最短的点为原点 
		for(j=1;j<=n;j++)
		if(book[j]==0&&dis[j]<min){
			min=dis[j];
			k=j;
		}
		book[k]=1;
		//以原点进行松弛操作
		for(j=1;j<=n;j++)
		if(dis[j]>dis[k]+e[k][j])
		dis[j]=dis[k]+e[k][j];
	}
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
