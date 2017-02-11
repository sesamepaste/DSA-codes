#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
vector<int> adjl[1000000];
int visited[1000000],radiald[1000000];
queue<int> q;
int M,N;

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int x,y;
		cin>>x>>y;
		adjl[x].push_back(y);
		adjl[y].push_back(x);
	}
	int source;
	cin>>source;
	memset(radiald,0,(N+1)*sizeof(int));
	q.push(source);
	radiald[source]=0;
	visited[source]=1;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		for(int i=0;i<adjl[temp].size();i++){
			if(visited[adjl[temp][i]]==0){
				q.push(adjl[temp][i]);
				radiald[adjl[temp][i]]=radiald[temp]+1;
				visited[adjl[temp][i]]=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout<<"Node numbered "<<i<<" at distance "<<radiald[i]<<" from source"<<endl;
	}
	return 0;
}
