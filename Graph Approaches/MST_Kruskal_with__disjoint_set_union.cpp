#include<iostream>
#include<utility>
#include<queue>
#include<cstdio>
using namespace std;

//change pq to sorted array


struct comparator{
	bool operator()(pair< pair< int,int >,long long > i, pair< pair< int,int >,long long > j){
		return i.second>j.second;
	}
};

int set[10002];

vector< pair< int,long long > > wadjl[10002];

priority_queue< pair< pair< int,int >,long long >,vector< pair< pair< int,int >,long long > >, comparator > pq_edge;

int M,N,u,v,d1,d2;
long long w;
unsigned long long sum;
bool t_u;

pair< pair< int,int >,long long > temp2,temp21;
pair< int,long long > temp1,temp11;

void initialize(){
	for(int i=0;i<10002;i++)
		set[i]=i;
}

int root(int x,int* a){
	*a=*a+1;
	if(set[x]!=x){
		set[x]=set[set[x]];				// ->path compression : Replace parent by grandparent, keep reducing depth 
		return root(set[x],a);
	}
	return x;
}
bool union1(int x, int y){
	d1=0;
	d2=0;
	int r1,r2;
	r1=root(x,&d1);
	r2=root(y,&d2);
	if(r1==r2){
		return false;
	}
	else{
		if(d1>d2)						// append to the bigger subtree to get new depth < max(d1,d2)+1
			set[r2]=set[r1];
		else
			set[r1]=set[r2];
		return true;
	}
}
int main(){
	scanf("%d %d \n",&N,&M);			//	@@ IMP scanf statements hav '\n' characters so take care of inputs and adjust @@
	for(int i=0;i<M;i++){
		scanf("%d %d %lld \n",&u,&v,&w);
		temp2.first.first=u;
		temp2.first.second = v;
		temp2.second=w;
		pq_edge.push(temp2);
	}
	initialize();
	while(!pq_edge.empty()){
		temp2=pq_edge.top();
		pq_edge.pop();
		t_u=union1(temp2.first.first,temp2.first.second);
		if(t_u==true)
			sum+=temp2.second;
	}
	cout<<sum;
	return 0;
}
