int cost[maxv][maxv];
int mincost[maxv];
bool used[maxv];
int V;

int prim()
{
	for(int i=0;i<V;i++)
		mincost[i]=inf,used[i]=false;
	mincost[0]=0;
	int res=0;
	while(1)
	{
		int v=-1;
		for(int u=0;u<V;u++)
			if(!used[u]&&(v==-1||mincost[u]<mincost[v]))v=u;
		if(v==-1)break;
		used[v]=true;
		res+=mincost[v];
		for(int u=0;u<V;u++)
			mincost[u]=min(mincost[u],cost[v][u]);
	}
	return res;
}