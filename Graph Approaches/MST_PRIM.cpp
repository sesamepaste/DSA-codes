#include<iostream>
#include<utility>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

//use visited array instead of disjoint union find

struct comparator{
	bool operator()(pair< pair< int,int >,long long > i, pair< pair< int,int >,long long > j){
		return (i.second>j.second);
	}
};

int set[10002];

vector< pair< int,long long > > wadjl[10002];

priority_queue< pair< pair< int,int >,long long >,vector< pair< pair< int,int >,long long > >, comparator > pq_edge;

int M,N,u,v,d1,d2,s;
long long w;
unsigned long long sum;
bool fr;

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
void union1(int x, int y){
	d1=0;
	d2=0;
	int r1,r2;
	r1=root(x,&d1);
	r2=root(y,&d2);
	if(d1>d2)						// append to the bigger subtree to get new depth < max(d1,d2)+1
		set[r2]=set[r1];
	else
		set[r1]=set[r2];
}
bool find(int x,int y){
	d1=0;
	d2=0;
	if(root(x,&d1)==root(y,&d2))
		return false;
	else
		return true;
}
int main(){
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d %d %lld \n",&u,&v,&w);
		temp1.second = w;
		temp1.first=v;
		wadjl[u].push_back(temp1);
		temp1.first=u;
		wadjl[v].push_back(temp1);
	}
	cin>>s;
	initialize();
	for(int i=0;i<wadjl[s].size();i++){
		temp2.second=wadjl[s][i].second;
		temp2.first.first=s;
		temp2.first.second=wadjl[s][i].first;
		pq_edge.push(temp2);
	}
	while(!pq_edge.empty()){
		temp2=pq_edge.top();
		pq_edge.pop();
		fr=find(temp2.first.first,temp2.first.second);
		if(fr==true){
			union1(temp2.first.first,temp2.first.second);
			for(int i=0;i<wadjl[temp2.first.second].size();i++){
				temp21.second=wadjl[temp2.first.second][i].second;
				temp21.first.first=temp2.first.second;
				temp21.first.second=wadjl[temp2.first.second][i].first;
				pq_edge.push(temp21);
			}
			sum+=temp2.second;
		}
	}
	cout<<sum;
	return 0;
}
