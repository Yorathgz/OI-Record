//Bellman-Ford�㷨�����Ż� (SPFA)
//����ϡ��ͼ�и�Ȩ��Դ���· 
//�ռ临�Ӷ�O(m)
//ʱ�临�Ӷ��Ҳ��O(nm) 
#include<iostream>
using namespace std;
int maxn=100,maxm=100; 
int main(){
	ios::sync_with_stdio(0);
	int n,m,i,j,k;
	int in[maxn+1],flag=0;//�жϸ�Ȩ��·����ʼ��in���� 
	int u[maxm+1],v[maxm+1],w[maxm+1];//uvw����Ҫ��m�����ֵ��1 
	int first[maxn+1],next[maxm+1];//firstҪ��n�����ֵ��1 
	int dis[maxn+1],book[maxn+1];//book����������¼��Щ�����Ѿ��ڶ����� 
	int que[10001]={0},head=1,tail=1;//����һ�����У�����ʼ������ 
	int inf=999999999;//������ 
	//��������ͱ��� 
	cin>>n>>m;
	//��ʼ��dis book first���� 
	for(i=1;i<=n;i++){
		in[i]=0;//δ�е���� 
		dis[i]=inf;//1�ŵ������ĳ�ʼ·�� 
		book[i]=0;//�տ�ʼ�����ڶ����� 
		first[i]=-1;//1~n������ʱ��û�б� 
	}
	dis[1]=0;
	//����� 
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		//�����ڽӱ� 
		next[i]=first[u[i]];
		first[u[i]]=i;
	}
	//1�Ŷ������ 
	que[tail]=1;tail++;
	in[1]=1;book[1]=1;//���������� 
	//���в�Ϊ��ʱѭ�� 
	while(head<tail){
		k=first[que[head]];//��ǰ��Ҫ����Ķ��׶��� 
		while(k!=-1){//ɨ�赱ǰ�������еı� 
			if(dis[v[k]]>dis[u[k]]+w[k]){//�ж��Ƿ��ɳڳɹ� 
				dis[v[k]]=dis[u[k]]+w[k];//���µ�v[k]·�� 
				if(book[v[k]]==0){
					//�ж϶���v[k]�Ƿ��ڶ����У�0��ʾ���ڶ����У����ĵ������� 
					//���������book�����ǣ��ж�ʱ��Ҫ��head��tailɨһ�飬�˷�ʱ�� 
					in[i]++;
					if(in[i]>n){
						flag=1;
						goto end;
					}
					que[tail]=v[k];
					tail++;
					book[v[k]]=1;//��Ǹĵ��Ѿ���� 
				}
			}
			k=next[k];
		}
		//���� 
		book[que[head]]=0;
		head++;
	}
	end:
	if(flag==1)
	cout<<"��ͼ���и�Ȩ��·";
	else 
	for(i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	return 0;
}
