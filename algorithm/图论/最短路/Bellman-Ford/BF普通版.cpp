//Bellman-Ford算法普通版
//适用稀疏图有负权单源最短路 
//空间复杂度O(m) 
//时间复杂度O(nm) 
#include<iostream>
using namespace std;
int main(){
	int dis[101],i,j,k,n,m,u[101],v[101],w[101];
	int inf=99999999;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	//初始化dis数组 
	for(i=1;i<=n;i++)
	dis[i]=inf;
	dis[1]=0;
	//Bellman-Ford算法核心语句 
	for(j=1;j<n;j++)
	for(i=1;i<=m;i++)
	if(dis[v[i]]>dis[u[i]]+w[i])
	dis[v[i]]=dis[u[i]]+w[i];
	//输出结果 
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
