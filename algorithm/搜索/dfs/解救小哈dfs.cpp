#include<iostream>
using namespace std;
int n,m,p,q;
int mins=9999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//��������
	int tx,ty,k;
	//�ж��Ƿ񵽴�С����λ��
	if(x==p&&y==q)
	{
		//������Сֵ
		if(step<mins)
		mins=step;
		return;//���ﷵ�أ����ص㣡����
	}
	//ö�������߷�
	for(k=0;k<=3;k++)
	{
		//������һ���������
		tx=x+next[k][0];
		ty=y+next[k][1];
		//�ж��Ƿ�Խ��
		if(tx<1||tx>n||ty<1||ty>m)
		continue;
		//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;//���������Ѿ��߹�
			dfs(tx,ty,step+1);//��ʼ������һ����
			book[tx][ty]=0;//���Խ�����ȡ�������ı��
		}
	}
	return;
}
int main()
{
	int i,j,startx,starty;
	//nΪ�У�mΪ�� 
	cin>>n>>m;
	//�����Թ� 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>a[i][j];
	//���������յ����� 
	cin>>startx>>starty>>p>>q;
	//����㿪ʼ���� 
	book[startx][starty]=1;//�������·���У���ֹ�ظ���
	dfs(startx,starty,0);
	cout<<mins;
	return 0;
}
