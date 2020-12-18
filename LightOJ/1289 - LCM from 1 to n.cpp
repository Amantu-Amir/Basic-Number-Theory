#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e8+5;
const int pnum=5761460;

int idx;
bitset<N+50>isPrime;
int prime[pnum];
unsigned int mult[pnum];

void sieve(){
	isPrime.reset();
	for(int i=2; (i*i)<=N; i++){
		if(isPrime[i]==0){
			for(int j=(i*i); j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(int i=2; i<=N; i++){
		if(isPrime[i]==0){
			prime[idx++]=i;
		}
	}
}

void preCalc(){
	mult[0]=prime[0];
	for(int i=1; i<idx; i++){
		mult[i]=mult[i-1]*prime[i];
	}
}

void rest_factors(int n){
	int temp,srt=sqrt(n+1);
	int x=lower_bound(prime,prime+idx,n)-prime;
	if(prime[x]!=n){x--;}
	unsigned int ans=mult[x];
	for(int i=0; prime[i]<=srt; i++){
		temp=n/prime[i];
		while(temp>=prime[i]){
			temp/=prime[i];
			ans*=prime[i];
		}
	}
	printf("%u\n",ans);
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sieve();
	preCalc();
	int t; scanf("%d",&t);
	for(int T=1; T<=t; T++){
		int n; scanf("%d",&n);
		printf("Case %d: ",T);
		rest_factors(n);
	}
	
	return 0;
}

