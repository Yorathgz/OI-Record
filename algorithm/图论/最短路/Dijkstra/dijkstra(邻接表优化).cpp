#include<iostream>
using namespace std;
//�ڽӱ��Ż�dijkstra�㷨������ϡ��ͼ(mԶС��n^2)��Դ���·��ʱ�临�Ӷ�ΪO(M+N)logN
//����ʵ���ڽӱ���ָ������ 
//������m==n^2,��(m+n)logn>n^2 
int inf=999999999;

int main(){
	ios::sync_with_stdio(0);
	int book[101]={0},dis[101],i,j,k,n,m,min;
	int u[101],v[101],w[101];//u[n],v[n],w[n]��ʾ�ڵ�n������ԭ��u[n]��Ŀ���v[n]��ȨֵΪw[n]
	int first[101],next[101];//first[u[n]]���涥��u[n]�ĵ�һ�������¼�룩�ı�ţ�-1��ʾ�գ�next[i]�洢 �����Ϊi�ıߡ��ġ���һ���ߡ��ı�� 
	cin>>n>>m;
	//��ʼ����¼ȷ����������1���·������ 
	book[1]=1;
	dis[1]=0; 
	for(i=1;i<=m;i++)
	first[i]=-1;
	//����·����
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		next[i]=first[u[i]];//��1���ߵ�next=-1,����һ����û����һ����
		first[u[i]]=i;//����u[i]�ĵ�һ���߸���Ϊ����¼���
	}
	//��ʼ������ֵ����,1��ֱ�Ӵﵽ�ĵ��Ԥ��ֵ��Ϊ��·������ 
	k=first[1];
	while(k!=-1){
		dis[v[k]]=w[k];
		k=next[k];
	}
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
