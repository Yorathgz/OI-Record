#include<iostream>
#include<string>
using namespace std;

int* overlay(const string& pattern){
	const int pattern_length=pattern.size();
	int *overlay_function=new int[pattern_length];
	int index;
	overlay_function[0]=-1;
	for(int i=1;i<pattern_length;i++){
		index=overlay_function[i-1];
		while(index>=0&&pattern[i]!=pattern[index+1])
			index=overlay_function[index];
		if(pattern[i]==pattern[index+1])
			overlay_function[i]=index+1;
			else
				overlay_function[i]=-1;
	}
	return overlay_function;
}

int KMP(const string&target,const string& pattern){
	int* next=overlay(pattern);
	const int tlen=target.size();
	const int plen=pattern.size();
	int pindex=0;
	int tindex=0;
	while(pindex<plen&&tindex<tlen){
		if(target[tindex]==pattern[pindex]){
			tindex++;
			pindex++;
		}
		else if(pindex==0)
				tindex++;
			else
				pindex=next[pindex]+1;
	}
	delete[] next;
	if(pindex==plen)
		return tindex-pindex;
	else
		return -1;
}

int main(){
	string pattern="ababacb";
	string target="abcdefgababacba";
	cout<<KMP(target,pattern);
	return 0;
}
