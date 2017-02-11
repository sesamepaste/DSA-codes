#include<stdio.h>
#include<time.h>
int min(int a,int b,int c)
{
	int minel=0;
	if(a<=b && a<=c)
	minel = a;
	else
	{
		if(a>b && a<=c)
		minel = b;
		if(a>c && a<=b)
		minel = c;
		if(a>c && a>b)
		{
			if(b<=c)
			minel = b;
			else
			minel = c;
		}
	}
	if(minel==a)
	return 1;
	if(minel==b)
	return 2;
	if(minel==c)
	return 3;
	else
	return 0;
}
void merge3(int s1,int b[],int s2,int c[],int s3,int d[],int a[])
{
	int i=0,j=0,k=0,l=0;
	while(j<s1 && k<s2 && l<s3)
	{
		if(min(b[j],c[k],d[l])==1)
		a[i++]=b[j++];
		if(min(b[j],c[k],d[l])==2)
		a[i++]=c[k++];
		if(min(b[j],c[k],d[l])==3)
		a[i++]=d[l++];
		if(min(b[j],c[k],d[l])==0)
		printf("MIN THROWING DEFAULT");
	}
	if(j==s1)
	{
		while(k<s2 && l<s3)
		{
			if(c[k]<=d[l])
			a[i++]=c[k++];
			else
			a[i++]=d[l++];
		}
		if(k==s2)
		{	
			while(l<s3)
			a[i++]=d[l++];
			if(l==s3)
			return;
		}
		if(l==s3)
		{
			while(k<s2)
			a[i++]=c[k++];
			if(k==s2)
			return;
		}
	}
	if(k==s2)
	{
		while(j<s1 && l<s3)
		{
			if(b[j]<=d[l])
			a[i++]=b[j++];
			else
			a[i++]=d[l++];
		}
		if(j==s1)
		{	
			while(l<s3)
			a[i++]=d[l++];
			if(l==s3)
			return;
		}
		if(l==s3)
		{
			while(j<s1)
			a[i++]=b[j++];
			if(j==s1)
			return;
		}
	}
	if(l==s3)
	{
		while(j<s1 && k<s2)
		{
			if(b[j]<=c[k])
			a[i++]=b[j++];
			else
			a[i++]=c[k++];
		}
		if(k==s2)
		{	
			while(j<s1)
			a[i++]=b[j++];
			if(j==s1)
			return;
		}
		if(j==s1)
		{
			while(k<s2)
			a[i++]=c[k++];
			if(k==s2)
			return;
		}
	}
}
void mergesort3(int n,int a[])
{	
	if(n>0)
	{
		if(n==1)
		return;
		else if(n==2)
		{
			if(a[0]>a[1])
			{
				int temp=a[0];
				a[0]=a[1];
				a[1]=temp;
			}	
		}
		else
		{
			int i,b[n/3],c[(n+1)/3],d[(n+2)/3];
			for(i=0;i<n/3;i++)
			b[i]=a[i];
			for(i=n/3;i<(n/3)+(n+1)/3;i++)
			c[i-(n/3)]=a[i];
			for(i=(n/3)+(n+1)/3;i<n;i++)
			d[i-(n/3)-(n+1)/3]=a[i];
			mergesort3(n/3,b);
			mergesort3((n+1)/3,c);
			mergesort3((n+2)/3,d);
			merge3(n/3,b,(n+1)/3,c,(n+2)/3,d,a);
		}
	}
	else
	printf("CALLED WITH INVALID ARRAY : SIZE < 0");
}
main()
{
clock_t t1,t2;
int i,n;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
scanf("%d",&a[i]);
double time;
t1=clock();
mergesort3(n,a);
t2=clock();
time=((double)(t2-t1))/CLOCKS_PER_SEC;
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\nMerge Sort completed \n");
printf("\n Time required for the mergesort operations is %f \n",time);
}
