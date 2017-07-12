//Bellman-Ford算法队列优化 (SPFA)
//适用稀疏图有负权单源最短路 
//空间复杂度O(m)
//时间复杂度最坏也是O(nm) 
#include<iostream>
using namespace std;
int maxn=100,maxm=100; 
int main(){
	ios::sync_with_stdio(0);
	int n,m,i,j,k;
	int in[maxn+1],flag=0;//判断负权回路，初始化in数组 
	int u[maxm+1],v[maxm+1],w[maxm+1];//uvw数组要比m的最大值大1 
	int first[maxn+1],next[maxm+1];//first要比n的最大值大1 
	int dis[maxn+1],book[maxn+1];//book数组用来记录哪些顶点已经在队列中 
	int que[10001]={0},head=1,tail=1;//定义一个数列，并初始化数列 
	int inf=999999999;//正无穷 
	//读入点数和边数 
	cin>>n>>m;
	//初始化dis book first数组 
	for(i=1;i<=n;i++){
		in[i]=0;//未有点入队 
		dis[i]=inf;//1号到其余点的初始路程 
		book[i]=0;//刚开始都不在队列中 
		first[i]=-1;//1~n顶点暂时都没有边 
	}
	dis[1]=0;
	//读入边 
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		//建立邻接表 
		next[i]=first[u[i]];
		first[u[i]]=i;
	}
	//1号顶点入队 
	que[tail]=1;tail++;
	in[1]=1;book[1]=1;//标记其已入队 
	//队列不为空时循环 
	while(head<tail){
		k=first[que[head]];//当前需要处理的队首顶点 
		while(k!=-1){//扫描当前顶点所有的边 
			if(dis[v[k]]>dis[u[k]]+w[k]){//判断是否松弛成功 
				dis[v[k]]=dis[u[k]]+w[k];//更新到v[k]路程 
				if(book[v[k]]==0){
					//判断顶点v[k]是否在队列中，0表示不在队列中，将改点加入队列 
					//如果不开个book数组标记，判断时需要从head到tail扫一遍，浪费时间 
					in[i]++;
					if(in[i]>n){
						flag=1;
						goto end;
					}
					que[tail]=v[k];
					tail++;
					book[v[k]]=1;//标记改点已经入队 
				}
			}
			k=next[k];
		}
		//出队 
		book[que[head]]=0;
		head++;
	}
	end:
	if(flag==1)
	cout<<"该图含有负权回路";
	else 
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
