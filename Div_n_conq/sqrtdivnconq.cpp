#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double sqrtdivnconqit(double n,double e)
{
	double low=1,high=n,mid=(low+high)/2;
	while(abs(mid*mid-n)>e)
	{
		if(mid*mid>n)
		{
			high=mid;
			mid=(low+high)/2;
		}
		else if(mid*mid<n)
		{
			low=mid;
			mid=(low+high)/2;
		}
	}
	return mid;
}
double sqrtdivnconqrec(double n,double low,double high,double e)
{
	if(low<high)
	{
		double mid=(low+high)/2;
		if(abs(mid*mid-n)<e)
			return mid;
		else
		{
			if(mid*mid<n)
				return sqrtdivnconqrec(n,mid,high,e);
			if(mid*mid>n)
				return sqrtdivnconqrec(n,low,mid,e);
		}
	}	
}
main()
{
	double n;
	cin>>n;
	double e = pow(10,-9);
	double root = sqrtdivnconqrec(n,0,n,e);
	cout<<root<<endl;
	printf("%7f",root*root);
}
