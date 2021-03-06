struct edge{
	int u,v,cost;
};

bool comp(const edge& e1,const edge& e2)
	return e1.cost<e2.cost;

edges es[maxe];
int V,E;

int kruskal()
{
	sort(es,es+E,comp);
	init_union_find(V);
	int res=0;
	for(int i=0;i<E;i++)
	{
		edges e=es[i];
		if(!same(e.u,e.v))
			unite(e.u,e.v),res+=e.cost;
	}
	return res;
}