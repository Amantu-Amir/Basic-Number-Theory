#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll N=1e6;
const ll mod=1e6+3;

ll fact[N+5];
void extended_euclide(ll a,ll b,ll &x, ll &y){
	if(b==0){
		x=1;y=0;
		return;
	}
	ll x1,y1;
	extended_euclide(b,a%b,x1,y1);
	x=y1;
	y=x1-y1*(a/b);
	return;
}

ll modular_inverse(ll a){
	ll x,y;
	extended_euclide(a,mod,x,y);
	return x;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fact[0]=1;
	for(ll i=1; i<=N; i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll n,r; scanf("%lld%lld",&n,&r);
		ll a=fact[n];
		ll b=modular_inverse(fact[r]*fact[n-r]);
		b=(b%mod+mod)%mod;
		ll res=(a*b)%mod;
		printf("Case %lld: %lld\n",T,res);
	}

	return 0;
}

