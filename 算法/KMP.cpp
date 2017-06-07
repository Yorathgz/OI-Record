#include<iostream>
using namespace std;

int* getnext(const string& p){
	int plen=p.length();
	int* next=new int[plen];
	next[0]=-1;
	int i,j;
	for(i=1;i<plen;i++){
		j=next[i-1];
		while(j+1&&p[i]!=p[j+1])
			j=next[j];
		if(p[i]==p[j+1])
			next[i]=j+1;
		else
			next[i]=-1;
	}
	return next;
}

int KMP(const string& t,const string& p){
	int *next=getnext(p);
	int tlen=t.length();
	int plen=p.length();
	int ti=0;
	int pi=0;
	while(ti<tlen&&pi<plen){
		if(t[ti]==p[pi]){
			ti++;
			pi++;
		}
		else if(pi==0)
			ti++;
			else
				pi=next[pi]+1;
	}
	if(pi==plen)
		return ti-pi;
	else
		return -1;
}

int main(void){
	string t="abcabcababc";
	string p="abab";
	cout<<KMP(t,p);
	return 0;
}