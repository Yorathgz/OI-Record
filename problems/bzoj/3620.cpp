#include<cstdio>
#include<cstring>
const int maxn=20000+10;
int n,next[maxn],ans=0,k;
char s[maxn];
void kmp(int p)
{
	for (int i=1;i<=n;++i) next[i]=p-1;
	for (int i=p+1;i<=n;++i)
	{
		int j=next[i-1];
		while (j+1!=p&&s[j+1]!=s[i]) j=next[j];
		if (s[j+1]==s[i]) j++; next[i]=j;
	}
	int j=next[p];
	for (int i=p+1;i<=n;++i)
	{
		while (j!=p-1&&s[j+1]!=s[i]) j=next[j];
		if (s[j+1]==s[i]) j++;
		while ((j-p+1)*2>=(i-p+1)) j=next[j];
		if (j-p+1>=k) ans++;
	}
}

int main()
{
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	int limit=n-k-k;
	for (int i=1;i<=limit;++i)kmp(i);
	printf("%d",ans);
	return 0;
}