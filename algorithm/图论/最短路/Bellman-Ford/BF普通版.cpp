//Bellman-Ford�㷨��ͨ��
//����ϡ��ͼ�и�Ȩ��Դ���· 
//�ռ临�Ӷ�O(m) 
//ʱ�临�Ӷ�O(nm) 
#include<iostream>
using namespace std;
int main(){
	int dis[101],i,j,k,n,m,u[101],v[101],w[101];
	int inf=99999999;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	//��ʼ��dis���� 
	for(i=1;i<=n;i++)
	dis[i]=inf;
	dis[1]=0;
	//Bellman-Ford�㷨������� 
	for(j=1;j<n;j++)
	for(i=1;i<=m;i++)
	if(dis[v[i]]>dis[u[i]]+w[i])
	dis[v[i]]=dis[u[i]]+w[i];
	//������ 
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
