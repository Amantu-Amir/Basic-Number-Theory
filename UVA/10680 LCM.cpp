#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e7+5;
const int mod=10;

bitset<N>isPrime;
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
	ll n;
	while(1){
		cin>>n;
		if(n==0){break;}
		if(n<5){
			ll res;
			if(n==1){res=1;}
			else if(n==2){res=2;}
			else if(n==3){res=6;}
			else{res=2;}
			cout<<res<<"\n";
			continue;
		}
		ll ans=1,two;
		for(ll i=0; prime[i]<=n; i++){
			ll temp=n,cnt=0;
			while(temp>=prime[i]){
				temp/=prime[i];
				cnt++;
			}
			if(prime[i]==2){
				two=cnt; continue;
			}
			if(prime[i]==5){
				ans=((ans%mod)*(1<<(two-cnt))%mod)%mod;
			}
			else{
				ll aa=prime[i]%mod;
				ll pp=powl(aa,cnt);
				ans=((ans%mod)*(pp%mod))%mod;
			}
		}
		cout<<ans%mod<<"\n";
	}

	return 0;
}

