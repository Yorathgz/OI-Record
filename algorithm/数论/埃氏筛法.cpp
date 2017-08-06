#include<iostream>
#include<cstring>
#define MAX_N 0xfffffff
using namespace std;

bool is_prime[MAX_N];
int prime[MAX_N];
int num;

int sieve(int n)
{
    num=0;
    for(int i=1;i<=n;i++)
        is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
        if(is_prime[i])
        {
            prime[num++]=i;
            for(int j=2*i;j<=n;j+=i)
                is_prime[j]=false;
        }
    return num;
}

void printf_prime()
{
    for(int i=0;i<num;i++)
        cout<<prime[i]<<" ";
    cout<<endl;
}

int main()
{
    int N;
    while(cin>>N)
    {
        memset(prime,0,sizeof(prime));
        cout<<sieve(N)<<endl;
        printf_prime();
    }
    return 0;
}
