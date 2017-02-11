#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
main()
{
	int a,b,c;
	srand(static_cast <unsigned int> (time(0)));
	a=1;
	b=pow(2,(sizeof(int)/2))-1;
	c=rand()%(b-a+1)+a;
	while(c<pow(2,(sizeof(int)/2))-11)
	{
	cout<<c;
	c=rand()%(b-c+1)+c;
	}
}
