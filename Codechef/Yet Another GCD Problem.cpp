

//https://www.codechef.com/problems/YAGCDP

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,a,b) for(ll i=a; i<b; i++) 
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//
const int N=1e6;

bitset<N+50>isPrime;
vector<ll>prime;
void sieve(){
	isPrime.reset();
	for(ll i=2; (i*i)<=N; i++){
		if(isPrime[i]==0){
			for(ll j=(i*i); j<=N; j+=i){
				isPrime[j]=1;
			}
		}
	}
	for(ll i=2; i<=N; i++){
		if(isPrime[i]==0){
			prime.pb(i);
		}
	}
}


int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	sieve();

	ll t=1; cin>>t;
	rep(T,1,t+1){
		ll n,a; cin>>n;
		map<ll,ll>mp;
		rep(i,0,n){
			cin>>a;
			for(ll j=0; prime[j]*prime[j]<=a; j++){
				if(a%prime[j]==0){
					mp[prime[j]]++;
					while(a%prime[j]==0){
						a/=prime[j];
					}
				}
			}
			if(a>1){
				mp[a]++;
			}
		}
		ll ans=0;
		for(auto it:mp){
			ans=max(ans,it.S);
		}
		if(ans==0){
			cout<<"-1\n";
		}
		else{
			cout<<n-ans<<"\n";
		}
	}
	return 0;
}

