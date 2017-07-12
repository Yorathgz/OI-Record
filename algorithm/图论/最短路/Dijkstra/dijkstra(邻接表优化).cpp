#include<iostream>
using namespace std;
//邻接表优化dijkstra算法：适用稀疏图(m远小于n^2)单源最短路，时间复杂度为O(M+N)logN
//数组实现邻接表，非指针链表 
//最坏的情况m==n^2,则(m+n)logn>n^2 
int inf=999999999;

int main(){
	ios::sync_with_stdio(0);
	int book[101]={0},dis[101],i,j,k,n,m,min;
	int u[101],v[101],w[101];//u[n],v[n],w[n]表示在第n条边中原点u[n]到目标点v[n]的权值为w[n]
	int first[101],next[101];//first[u[n]]保存顶点u[n]的第一条（最后录入）的编号，-1表示空，next[i]存储 “编号为i的边”的“下一条边”的编号 
	cin>>n>>m;
	//初始化记录确定点的数组和1点的路径长度 
	book[1]=1;
	dis[1]=0; 
	for(i=1;i<=m;i++)
	first[i]=-1;
	//读入路径长
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		next[i]=first[u[i]];//第1条边的next=-1,即第一条边没有下一条边
		first[u[i]]=i;//顶点u[i]的第一条边更新为最新录入边
	}
	//初始化估计值数组,1能直接达到的点的预测值设为其路径长度 
	k=first[1];
	while(k!=-1){
		dis[v[k]]=w[k];
		k=next[k];
	}
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
		j=first[k];
		while(j!=-1){
			if(dis[v[j]]>dis[k]+w[j])
			dis[v[j]]=dis[k]+w[j];
			j=next[j];
		} 
	}
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
