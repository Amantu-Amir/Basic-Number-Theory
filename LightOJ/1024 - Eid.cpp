#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e4+50;

ll ar[N+5];
bool isPrime[N+5];
vector<ll>prime;
void sieve(){
	prime.pb(2);
	for(ll i=3; i<=N; i+=2){
		if(isPrime[i]==0){
			prime.pb(i);
			for(ll j=(i*i); j<=N; j+=(i*2)){
				isPrime[j]=1;
			}
		}
	}
}

string multiply(string a, ll b){
	ll carry=0,sz=a.size();
	for(ll i=0; i<sz; i++){
		carry+=(a[i]-'0')*b;
		a[i]=(carry%10)+'0';
		carry/=10;
	}
	while(carry>0){
		a+=(carry%10)+'0';
		carry/=10;
	}
	return a;
}

void factors(ll a){
	ll srt=sqrt(a+1);
	for(ll j=0; prime[j]<=srt; j++){
		ll mult=1;
		while(a%prime[j]==0){
			a/=prime[j]; mult*=prime[j];
		}
		ar[j]=max(ar[j],mult);
	}
	if(a>1){
		ll k=lower_bound(all(prime),a)-prime.begin();
		ar[k]=max(ar[k],a);
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sieve();
	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll n,a; scanf("%lld",&n);
		for(ll i=1; i<=n; i++){
			scanf("%lld",&a);
			factors(a);
		}
		string lcm="1";
		ll sz=prime.size();
		for(ll i=0; i<sz; i++){
			if(ar[i]>0){
				lcm=multiply(lcm,ar[i]);
			}
		}
		sz=lcm.size();
		reverse(all(lcm));
		cout<<"Case "<<T<<": "<<lcm<<"\n";
		for(ll i=0; i<=N; i++){
			ar[i]=0;
		}
	}
	return 0;
}



