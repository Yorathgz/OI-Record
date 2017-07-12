//Bellman-Ford算法优化版+检测有无负权回路 
//适用稀疏图有负权单源最短路 
//空间复杂度O(m)
//时间复杂度O(nm)
#include<iostream>
using namespace std;
int main(){
	int dis[101],i,j,k,n,m,u[101],v[101],w[101],bak[101];
	bool check,flag;
	int inf=99999999;
	cin>>n>>m;
	//读入边 
	for(i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	//初始化dis数组 
	for(i=1;i<=n;i++)
	dis[i]=inf;
	dis[1]=0;
	//Bellman-Ford算法核心语句 
	for(j=1;j<n;j++){
		check=false;
		for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i]){
			dis[v[i]]=dis[u[i]]+w[i];
			check=true;//dis数组已更新，改变check的值 
		}
		//检测dis数组是否有更新 
		if(check==false) break;//没更新则已得出结果，提前结束算法 
	}
	//检测负权回路
	flag=false;
	for(i=1;i<=m;i++)
	if(dis[v[i]]>dis[u[i]]+w[i])
	flag=true; 
	if(flag==true)
	cout<<"此图含有负权回路，无最短路";
	//输出结果
	else
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
