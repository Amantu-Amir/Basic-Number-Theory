#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long int ull;
const int N=5e6;

ull phi[N+5];
void init(){
	for(int i=0; i<=N; i++){
		phi[i]=i;
	}
	for(int i=2; i<=N; i++){
		if(phi[i]==i){
			for(int j=i; j<=N; j+=i){
				phi[j]-=phi[j]/i;
			}
		}
		phi[i]*=phi[i]; phi[i]+=phi[i-1];
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	init();
	int t; scanf("%d",&t);
	for(int T=1; T<=t; T++){
		int a,b; scanf("%d%d",&a,&b);
		ull res=phi[b]-phi[a-1];
		printf("Case %d: %llu\n",T,res);
	}
	return 0;
}

