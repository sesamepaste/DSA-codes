#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;

//Works in c++11 and later because of use of "auto" keyword on line 51 

//Comparator to use priority_queue as min_heap instead of max_heap
struct comparator{
	bool operator()(pair<int,int> i,pair<int,int> j){
		return (i.first > j.first);
	}
};

vector< pair<int,int> > wadjl[1000000];			//Adjacency list containing neighbours of a vertex(second) with edge weight(first)

int srtdst[1000000];							//Array containing information about shortest distance

priority_queue<pair<int,int>,vector< pair<int,int> >,comparator > pq;		//Implementation of min_heap (Can use comparator instead of min)

int M,N;
pair<int,int> temp,temp1;
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v,w;
		cin>>u>>v>>w;
		temp.first=w;
		temp.second=u;
		wadjl[v].push_back(temp);
		temp.second=v;
		wadjl[u].push_back(temp);
	}
	int source;
	cin>>source;
	memset(srtdst,1000000,(N+1)*sizeof(int));				//make shortest distance for everything INT_MAX
	temp.first=0;
	temp.second=source;
	srtdst[source]=0;
	pq.push(temp);
	while(!pq.empty()){
		temp1 = pq.top();
		pq.pop();
		for(auto x : wadjl[temp1.second]){				//auto construct causes requirement of c++11 or later
			int newdist=temp1.first+x.first;
			if(newdist<srtdst[x.second]){				//If new distance is lesser, refactor everything ahead
				x.first=newdist;
				srtdst[x.second]=x.first;
				pq.push(x);
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<"Node numbered "<<i<<" at distance "<<srtdst[i]<<" from source"<<endl;
	}
	return 0;
}
