    #include<iostream>
    #include<utility>
    #include<queue>
    #include<cstdio>
    using namespace std;
     
    struct comparator{
        bool operator()(pair< pair< int,int >,long long > i, pair< pair< int,int >,long long > j){
            return i.second>j.second;
        }
    };
     
    struct cl{
        int repr;
        int volume = 1;
    };
     
     
    cl set[10002];
    vector< pair< int, long long > > wadjl[10002];
     
    priority_queue< pair< pair< int,int >,long long >,vector< pair< pair< int,int >,long long > >, comparator > pq_edge;
     
    int M, N, u, v ,d1, d2, r1, r2, s, fc=0;
    long long w;
    unsigned long long sum;
    bool t_u;
     
    pair< pair< int,int >,long long > temp2,temp21;
    pair< int,long long > temp1,temp11;
     
    void initialize(int N){
        for(int i=0;i<N;i++){
            set[i].repr = i;
            set[i].volume = 1;
        }
    }
     
    int root(int x,int* a){
        *a=*a+1;
        if(set[x].repr!=x){
            set[x].repr=set[set[x].repr].repr;                // ->path compression : Replace parent by grandparent, keep reducing depth
            return root(set[x].repr,a);
        }
        return x;
    }
    bool union1(int x, int y){
        d1=0;
        d2=0;
        r1=root(x,&d1);
        r2=root(y,&d2);
        if(r1!=r2){
            if(d1>d2){                        // append to the bigger subtree to get new depth < max(d1,d2)+1
                set[r2].repr=set[r1].repr;
                set[r1].volume += set[r2].volume;
                if(set[r1].volume == N)
                    fc=1;
            }
            else{
                set[r1].repr=set[r2].repr;
                set[r2].volume += set[r1].volume;
                if(set[r2].volume == N)
                    fc=1;
            }
            return true;
        }
        return false;
    }
    int main(){
        cin.tie(NULL);
        std::ios::sync_with_stdio(false);
        cin>>N>>M;
        for(int i=0;i<M;i++){
            cin>>u>>v>>w;
            temp2.first.first=u-1;
            temp2.first.second = v-1;
            temp2.second=w;
            pq_edge.push(temp2);
        }
        cin>>s;
        initialize(N);
        while(!pq_edge.empty() && !fc){
            temp2=pq_edge.top();
            t_u=union1(temp2.first.first,temp2.first.second);
            if(t_u==true)
                sum+=temp2.second;
            pq_edge.pop();
        }
        cout<<sum;
        return 0;
    } 
