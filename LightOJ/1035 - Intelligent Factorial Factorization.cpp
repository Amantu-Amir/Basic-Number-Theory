#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1000;

bool isPrime[N+5];
vector<ll>prime,v;
void sieve(){
	prime.pb(2);
	for(ll i=3; i<N; i+=2){
		if(isPrime[i]==0){
			prime.pb(i);
			for(ll j=(i*i); j<N; j+=(i*2)){
				isPrime[j]=1;
			}
		}
	}
}


void divisors(ll n){
	ll srt=sqrt(n+1);
	for(ll i=0; prime[i]<=srt; i++){
		while(n%prime[i]==0){
			n/=prime[i];
			v.pb(prime[i]);
		}
	}
	if(n>1){v.pb(n);}
}


int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	sieve();
	ll t; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		for(ll i=2; i<=n; i++){
			divisors(i);
		}
		ll sz=v.size();
		map<ll,ll>m;
		for(ll i=0; i<sz; i++){m[v[i]]++;}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		sz=v.size();
		printf("Case %lld: %lld = ",T,n);
		for(ll i=0; i<sz; i++){
			printf("%lld (%lld)",v[i],m[v[i]]);
			if(i!=(sz-1)){
				printf(" * ");
			}
		}
		printf("\n"); v.clear();
	}
	return 0;
}


