#include<stdio.h>
#include<time.h>
#
int comparevar=0;
int swapvar=0;
int compare(int a, int b)
{
	comparevar++;
	return a>b?1:0;
}
void swap(int *a, int *b)
{
	swapvar++;
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int l,int r,int a[])
{
	int i,j,P=a[r];		
	i=l;
	for(j=l;j<r;j++)
	{
		if(a[j]<=P)
		{
			swap(&a[j],&a[i]);	
			i++;
		}
	}
	swap(&a[i],&a[r]);
	return i;
}	
void merge(int s1,int b[],int s2,int c[],int a[])
{
	
	int i=0,j=0,k=0;
	while(j<s1 && k<s2)
	{
		if(compare(b[j],c[k]))
		a[i++]=c[k++];
		else
		a[i++]=b[j++];
	}
	if(j==s1)
	{
		while(k<s2)
		{
			a[i++]=c[k++];
		} 
		if(k==s2)
		return;
	}
	if(k==s2)
	{
		while(j<s1)
		{
			a[i++]=b[j++];
		}
		if(j==s1)
		return;
	}

}
void mergesort(int n, int a[])
{	
	int i;
	if(n==1)
	return;
	else
	{
		int b[n/2],c[(n+1)/2];
		for(i=0;i<n/2;i++)
		b[i]=a[i];
		for(i=n/2;i<n;i++)
		c[i-n/2]=a[i];
		mergesort(n/2,b);
		mergesort((n+1)/2,c);
		merge(n/2,b,(n+1)/2,c,a);		
	}
}
void quicksort(int l,int r,int a[])
{	
	if(l<r)
	{
	int q=partition(l,r,a);
	quicksort(l,q-1,a);
	quicksort(q+1,r,a);
	}
}
main()
{
clock_t t1,t2,t3;
int i,n;
scanf("%d",&n);
int a[n],b[n];
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
	b[i]=a[i];
}
double time1,time2;
t1=clock();
mergesort(n,a);
t2=clock();
quicksort(0,n-1,b);
t3=clock();
time1=((double)(t2-t1))/CLOCKS_PER_SEC;
time2=((double)(t3-t2))/CLOCKS_PER_SEC;
for(i=0;i<n;i++)
{
	printf("%d ",a[i]);
	printf("%d\n",b[i]);
}	
printf("\nMerge Sort completed with %d comparisons and Quicksort completed with %d swaps\n",comparevar,swapvar);
printf("\n Time required for the mergesort is : %f and for quicksort is : %f \n",time1,time2);
}
