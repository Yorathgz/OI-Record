#include<iostream>
using namespace std;
struct note{
	int x;//������ 
	int y;//������ 
	int f;//���ڵ㣬�������·�������ⲻ��Ҫ 
	int s;//���� 
};
int main(){
	struct note que[2501];//���Ϊnm 
	int a[51][51]={0},book[51][51]={0};
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//�������� 
	int head,tail;
	int i,j,k,l,n,m,startx,starty,p,q,tx,ty,flag;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>a[i][j];
	cin>>startx>>starty>>p>>q;
	//���г�ʼ�� 
	head=1;
	tail=1; 
	//����������� 
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	//����Ƿ�ﵽĿ��� 
	flag=0;
	while(head<tail){
		//ö���ĸ����� 
		for(k=0;k<=3;k++){
			//������һ��������� 
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ�� 
			if(tx<1||tx>n||ty<1||ty>m)
			continue;
			//�ж��Ƿ�Ϊ�ϰ�����Ѿ���·���� 
			if(a[tx][ty]==0&&book[tx][ty]==0){
				//����߹�������ֻ���һ�Σ����Ժ����Ѳ�ͬ������Ҫ��book��ԭ 
				book[tx][ty]=1;
				//���뵽������ 
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;//��Ϊ��head��չ�����ĵ㣬���Ը��ڵ���head 
				que[tail].s=que[head].s+1;//�����Ǹ��ڵ�Ĳ�����һ 
				tail++;
			}
			//����ﵽĿ����ˣ�ֹͣ��չ������������˳�ѭ�� 
			if(tx==p&&ty==q){
				flag=1;
				break;
			}
		}
		if(flag==1)
		break;
		head++;//һ������չ����֮�󽫸õ���� 
	}
	//tail�Ƕ�β�ĺ�һλ������Ҫ��һ 
	cout<<que[tail-1].s;
	return 0;
}
