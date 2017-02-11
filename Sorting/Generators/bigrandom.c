#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
	time_t t;
	int i,fsize=pow(10,5)+7;
	srand((unsigned)time(&t)+pow(10,3)+67);
	printf("%d\n",fsize);
	for(i=0;i<fsize;i++)
	printf("%d\n",rand()) ;
}
