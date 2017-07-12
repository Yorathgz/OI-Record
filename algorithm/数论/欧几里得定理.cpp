int o_gcd(int a,int b)
{
	if(b==0)return a;
	else return o_gcd(b,a%b);
}

int e_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int gcd=e_gcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	return gcd;
}