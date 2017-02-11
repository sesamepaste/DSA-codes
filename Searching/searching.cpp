#include<iostream>
#include<cstdio>
using namespace std;
int linsearch(int t,int n,int a[])
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==t)
		return i;
	}
	//cout<<"Target value not found";
	return -1;
}
int binsearchrec(int t,int l,int r,int a[])
{
	if(l>r)
	{
		//cout<<"Target item not found";
		return -1;
	}
	else
	{
		int mid=l + (r-l)/2;
		if(a[mid]<t)
		return binsearchrec(t,mid+1,r,a);
		else if(a[mid]>t)
		return binsearchrec(t,l,mid-1,a);
		else
		return mid;
	}

}
int binsearchit(int t,int n,int a[]) 	//Doesn't necessarily give first occurence
{
	int i,min=0,max=n-1,mid=min + (max-min)/2;
	while(min<=max)
	{
		if(a[mid]>t)
		{
			max=mid-1;
			mid=min + (max-min)/2;
		}
		else if(a[mid]<t)
		{
			min=mid+1;
			mid=min + (max-min)/2;
		}
		else
		return mid;
	}
	//cout<<"Target value not found";
	return -1;
}
main()
{
	int n,t;
	cin>>n;
	cin>>t;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<linsearch(t,n,a);
}
