#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N=15e5;
vector<ll>prime;
bool isPrime[N+5];
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

ll nod(ll n){
	ll srt=sqrt(n+1),div=1;
	for(ll i=0; prime[i]<=srt; i++){
		if(n%prime[i]==0){
			ll cnt=1;
			while(n%prime[i]==0){
				n/=prime[i]; cnt++;
			}
			div*=cnt; srt=sqrt(n);
		}
	}
	if(n>1){div*=2;}
	return div;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sieve();
	ll t; scanf("%lld\n",&t);
	for(ll T=1; T<=t; T++){
		ll n; scanf("%lld",&n);
		ll ans=nod(n)-1;
		printf("Case %lld: %lld\n",T,ans);
	}
	return 0;
}

