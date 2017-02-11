#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define ll long long

string S;

ll M = 1000000007;

ll H[10001];
ll pow26 [10001],invpow26[10001];

ll modexp(ll a,ll n,ll M){			//Modular Exponentiation to calculate (a^n)%M  in O(log(n)) time using div_n_conq
    if(n==0)
        return 1;
    if(n==1)
        return a%M;
    else{
        long long b,c;
        if(n%2==0){
        	b=modexp(a,n/2,M);
        	c=b;
        	return (b*c)%M;
        }
        else{
            b=modexp(a,n/2,M);
            c=modexp(a,(n+1)/2,M);
            return (b*c)%M;
        }
    }
}

ll inverse(ll a,ll M){
	return modexp(a,M-2,M);
}

void precompute_mod26(ll pow26[],ll invpow26[],ll M){
	pow26[0]=1;
	invpow26[0]=1;
	for(int i=1;i<10001;i++){
		pow26[i]=(pow26[i-1]*26)%M;
		invpow26[i]=inverse(pow26[i],M);
	}
}

void prefix_hash(string S,ll H[],ll pow26[],ll M){

	ll slen= S.size();
	H[0]=S[0]-'a';
	for(int i=1;i<slen;i++){
		H[i]=H[i-1]+(S[i]-'a')*pow26[i];
		H[i]%=M;
	}
}
int main(){
	
	return 0;
}