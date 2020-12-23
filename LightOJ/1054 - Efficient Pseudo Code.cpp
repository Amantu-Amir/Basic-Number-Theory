#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll N=1e6;
const ll mod=1e9+7;

ll idx;
vector<ll>prime;
bitset<N+5>isPrime;
void sieve(){
	isPrime.reset();
	for(ll i=2; (i*i)<=N; i++){
		if(isPrime[i]==0){
			for(ll j=(i*i); j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(ll i=2; i<N; i++){
		if(isPrime[i]==0){
			prime.pb(i);
		}
	}
}

ll big_mod(ll b,ll p){
	if(p==1){return b%mod;}
	if(p%2==1){
		ll odd=b%mod;
		ll even=big_mod(b,p-1);
		return (odd*even)%mod;
	}
	if(p%2==0){
		ll even=big_mod(b,p/2);
		ll temp=even*even;
		return (even*even)%mod;
	}
}

void extended_euclid(ll a,ll b,ll &x, ll &y){
	if(b==0){
		x=1;y=0; 
		return;
	}
	ll x1,y1;
	extended_euclid(b,a%b,x1,y1);
	x=y1;
	y=x1-y1*(a/b);
	return;
}

ll modular_inverse(ll a){
	ll x,y;
	extended_euclid(a,mod,x,y);
	return x;
}

ll solve(ll n,ll m){
	ll srt=sqrt(n+1),res=1;
	for(ll i=0; prime[i]<=srt; i++){
		if(n%prime[i]==0){
			ll cnt=0;
			while(n%prime[i]==0){
				n/=prime[i]; cnt++;
			}
			ll a=(big_mod(prime[i],(cnt*m)+1)-1+mod)%mod;
			ll x=modular_inverse(prime[i]-1);
			x=(x%mod+mod)%mod;
			a=(a*x)%mod;
			res=(res*a)%mod;
		}
	}
	if(n>1){
		ll a=(big_mod(n,m+1)-1+mod)%mod;
		ll x=modular_inverse(n-1);
		x=(x%mod+mod)%mod;
		a=(a*x)%mod;
		res=(res*a)%mod;
	}
	return res;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sieve();
	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll n,m; scanf("%lld%lld",&n,&m);
		ll res=solve(n,m);
		printf("Case %lld: %lld\n",T,res);
	}
	return 0;
}

