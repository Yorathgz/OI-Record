#include<iostream>
#include<cstring>
using namespace std;

//type1

string s0,s1,st;
char ts[26];

int main()
{
	cin>>s1>>s0>>st;
	int n=s0.size();
	for(int i=0;i<n;i++)
	{
		if(!ts[s1[i]-'A'])
			ts[s1[i]-'A']=s0[i];
		else if(ts[s1[i]-'A']!=s0[i]) //case:3
		{
			cout<<"Failed";
			return 0;
		}
	}
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			if(ts[i]==ts[j]) //case:3
			{
				cout<<"Failed";
				return 0;
			}
	for(int i=0;i<26;i++) //case:2
		if(!ts[i])
		{
			cout<<"Failed";
			return 0;
		}
	n=st.size();
	for(int i=0;i<n;i++)
		cout<<char(ts[st[i]-'A']);
	return 0;
}