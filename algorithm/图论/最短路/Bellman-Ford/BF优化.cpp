//Bellman-Ford�㷨�Ż���+������޸�Ȩ��· 
//����ϡ��ͼ�и�Ȩ��Դ���· 
//�ռ临�Ӷ�O(m)
//ʱ�临�Ӷ�O(nm)
#include<iostream>
using namespace std;
int main(){
	int dis[101],i,j,k,n,m,u[101],v[101],w[101],bak[101];
	bool check,flag;
	int inf=99999999;
	cin>>n>>m;
	//����� 
	for(i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	//��ʼ��dis���� 
	for(i=1;i<=n;i++)
	dis[i]=inf;
	dis[1]=0;
	//Bellman-Ford�㷨������� 
	for(j=1;j<n;j++){
		check=false;
		for(i=1;i<=m;i++)
		if(dis[v[i]]>dis[u[i]]+w[i]){
			dis[v[i]]=dis[u[i]]+w[i];
			check=true;//dis�����Ѹ��£��ı�check��ֵ 
		}
		//���dis�����Ƿ��и��� 
		if(check==false) break;//û�������ѵó��������ǰ�����㷨 
	}
	//��⸺Ȩ��·
	flag=false;
	for(i=1;i<=m;i++)
	if(dis[v[i]]>dis[u[i]]+w[i])
	flag=true; 
	if(flag==true)
	cout<<"��ͼ���и�Ȩ��·�������·";
	//������
	else
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
