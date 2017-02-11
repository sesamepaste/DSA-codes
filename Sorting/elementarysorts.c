#include<stdio.h>
int comparevar=0;
int swapvar=0;
int compare(int a, int b)
{
	comparevar++;
	return a>b?1:0;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	swapvar++;
}
void insertionsort(int n,int a[])
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && compare(a[j],temp))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}	
}
void selectionsort(int n, int a[])
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(compare(a[min],a[j]))
			min=j;	
		}
			swap(&a[min],&a[i]);
	}	
}
void bubblesort(int n, int a[])
{
	int i,j;
	for(i=1;i<n;i++)
	{
			for(j=0;j<n-i;j++)
			{
				if(compare(a[j],a[j+1]))
				{
					swap(&a[j+1],&a[j]);
				}
			}
	}
}
main()
{
	int n,i;
	scanf("%d",&n);
	int a[n],b[n],c[n];
	for(i=0;i<n;i++)
	{
		scanf("%d ",&a[i]);
		b[i]=a[i];
		c[i]=a[i];
	}
	insertionsort(n,a);
	printf("Insertion sort completed with %d compare operations\n",comparevar);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);	
		
	}
	printf("\n");
	comparevar=0;
	selectionsort(n,b);
	printf("Selection sort completed with %d compare operations and %d swap operaions\n",comparevar,swapvar);
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);	
		
	}	
	printf("\n");
	comparevar=0;
	swapvar=0;
	bubblesort(n,c);
	printf("Bubble sort completed with %d compare operations and %d swap operations\n",comparevar,swapvar);
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);	
		
	}	
	printf("\n");
	}
