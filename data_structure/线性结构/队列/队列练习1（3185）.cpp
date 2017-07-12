#include<iostream>
#include<cstdio>
using namespace std;

struct queue{
	int data[10001];
	int head;
	int tail;
};

int main(){
	struct queue q;
	int i,j,n;
	q.head=1;
	q.tail=1;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		if(j==1){
			cin>>q.data[q.tail];
			q.tail++;
		}
		if(j==2) q.head++;
	}
	if(q.head<q.tail)
	cout<<q.data[q.head];
	if(q.head>=q.tail)
	cout<<"impossible!";
	return 0;
}
