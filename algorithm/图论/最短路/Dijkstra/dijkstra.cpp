#include<iostream>
using namespace std;
//��ͨdijkstra�㷨�����õ�Ԫ���·��ʱ�临�Ӷ�ΪO(n^2) 
int inf=999999999;

int main(){
	ios::sync_with_stdio(0);
	int e[101][101],book[101]={0},dis[101],i,j,k,n,m,a,b,c,min;
	cin>>n>>m;
	//��ʼ��·����������ͼ�¼ȷ��������� 
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i==j) e[i][j]=0;
	else e[i][j]=inf;
	book[1]=1;
	//����·���� 
	for(i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a][b]=c;
	}
	//��ʼ������ֵ���� 
	for(i=1;i<=n;i++)
	dis[i]=e[1][i];
	//dijkstra�㷨������� 
	for(i=1;i<n;i++){
		min=inf;
		//��δȷ�����й���·��ֵ��̵ĵ�Ϊԭ�� 
		for(j=1;j<=n;j++)
		if(book[j]==0&&dis[j]<min){
			min=dis[j];
			k=j;
		}
		book[k]=1;
		//��ԭ������ɳڲ���
		for(j=1;j<=n;j++)
		if(dis[j]>dis[k]+e[k][j])
		dis[j]=dis[k]+e[k][j];
	}
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
