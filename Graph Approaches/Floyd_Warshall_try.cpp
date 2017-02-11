#include<iostream>
#include<algorithm>

#define INF 10000007

using namespace std;

int N,M;

int main(){
	cin>>N>>M;
	int A[N][N];
	int B[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j] = INF;
			B[i][j] = INF;
		}
	}
	int x,y,w;
	for(int i=0;i<M;i++){
		cin>>x>>y>>w;
		A[x][y] = w;
		A[y][x] = w;
		B[x][y] = w;
		B[y][x] = w;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(B[j][k] > B[j][i] + B[i][k])
					B[j][k] = B[j][i] + B[i][k];
			}
		}
	}


	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
}