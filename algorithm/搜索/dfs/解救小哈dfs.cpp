#include<iostream>
using namespace std;
int n,m,p,q;
int mins=9999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//方向数组
	int tx,ty,k;
	//判断是否到达小哈的位置
	if(x==p&&y==q)
	{
		//更新最小值
		if(step<mins)
		mins=step;
		return;//这里返回，划重点！！！
	}
	//枚举四种走法
	for(k=0;k<=3;k++)
	{
		//计算下一个点的坐标
		tx=x+next[k][0];
		ty=y+next[k][1];
		//判断是否越界
		if(tx<1||tx>n||ty<1||ty>m)
		continue;
		//判断该点是否为障碍物或者已经在路径中
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//标记这个点已经走过
			dfs(tx,ty,step+1);//开始尝试下一个点
			book[tx][ty]=0;//尝试结束，取消这个点的标记
		}
	}
	return;
}
int main()
{
	int i,j,startx,starty;
	//n为行，m为列 
	cin>>n>>m;
	//读入迷宫 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>a[i][j];
	//读入起点和终点坐标 
	cin>>startx>>starty>>p>>q;
	//从起点开始搜索 
	book[startx][starty]=1;//标记已在路径中，防止重复走
	dfs(startx,starty,0);
	cout<<mins;
	return 0;
}
