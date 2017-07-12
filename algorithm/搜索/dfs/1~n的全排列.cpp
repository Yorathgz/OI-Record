#include<iostream>
using namespace std;

int n,box[101],book[101];

void dfs(int step){
	int i; //i若在函数外定义则只输出一组 
	if(step==n+1){
		for(i=1;i<=n;i++)
		cout<<box[i];
		cout<<endl;
		return;
	}
	for(i=1;i<=n;i++)
		if(book[i]==0){
			box[step]=i;
			book[i]=1;
			dfs(step+1);
			book[i]=0;
		}
	return;
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}
