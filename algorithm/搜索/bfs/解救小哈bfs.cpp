#include<iostream>
using namespace std;
struct note{
	int x;//横坐标 
	int y;//纵坐标 
	int f;//父节点，用以输出路径，本题不需要 
	int s;//步数 
};
int main(){
	struct note que[2501];//最大为nm 
	int a[51][51]={0},book[51][51]={0};
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//方向数组 
	int head,tail;
	int i,j,k,l,n,m,startx,starty,p,q,tx,ty,flag;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>a[i][j];
	cin>>startx>>starty>>p>>q;
	//队列初始化 
	head=1;
	tail=1; 
	//插入入口坐标 
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	//标记是否达到目标点 
	flag=0;
	while(head<tail){
		//枚举四个方向 
		for(k=0;k<=3;k++){
			//计算下一个点的坐标 
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界 
			if(tx<1||tx>n||ty<1||ty>m)
			continue;
			//判断是否为障碍物或已经在路径中 
			if(a[tx][ty]==0&&book[tx][ty]==0){
				//标记走过，宽搜只入队一次，所以和深搜不同，不需要将book还原 
				book[tx][ty]=1;
				//插入到队列中 
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;//因为是head拓展出来的点，所以父节点是head 
				que[tail].s=que[head].s+1;//步数是父节点的步数加一 
				tail++;
			}
			//如果达到目标点了，停止拓展，任务结束，退出循环 
			if(tx==p&&ty==q){
				flag=1;
				break;
			}
		}
		if(flag==1)
		break;
		head++;//一个点拓展结束之后将该点出队 
	}
	//tail是队尾的后一位，所以要减一 
	cout<<que[tail-1].s;
	return 0;
}
