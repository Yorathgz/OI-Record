#include<iostream>
#include<string>
using namespace std;

int list[],data[],first[],next[];

// Hash Function
int hash_func(string x)
{
    int seed=131;
    int m=10007;
    int _hash=0;
    int len=x.length();
    for(int i=0;i<len;i++)
        _hash=(_hash*seed+x[i]-'0')%m;
    return _hash;
}

int find(string h)
{
    int key=hash(h);
    int u=list[key];
    while(u)
    {
        if(data[u]==h)
            return 1;
        u=next[u];
    }
    return 0;
}

int add(string h)
{
    key=hash(h);
    int u=list[sum];
    while(u)
    {
        if(data[u]==h)
            return 0;
        u=next[u];
    }
    cnt++;
    data[cnt]=h;
    next[cnt]=list[sum];
    list[sum]=cnt;
    return 1;
}

int main()
{
    return 0;
}
