#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	cin>>n;
	head=NULL;
	for(i=1;i<=n;i++){
		cin>>a;
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;
		p->next=NULL;
		if(head==NULL) head=p;
		else q->next=p;
		q=p;
	}
	cin>>a;
	t=head;
	while(t!=NULL){
		if(t->next==NULL||t->next->data>a){
			p=(struct node *)malloc(sizeof(struct node));
			p->data=a;
			p->next=t->next;
			t->next=p;
			break;
		}
		t=t->next;
	}
	t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
	return 0;
}
