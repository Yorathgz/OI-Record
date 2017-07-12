#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int q[100001];
	int i,j,n;
	int head=1,tail=1;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		if(j==1){
			cin>>q[tail];
			tail++;
		}
		if(j==2)
		head++;
		if(j==3)
		cout<<q[head]<<endl;
	}
	return 0;
}
