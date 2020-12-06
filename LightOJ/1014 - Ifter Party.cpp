#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

set<ll>st;
void divisors(ll n){
	ll srt=sqrt(n);
	for(ll i=1; i<=srt; i++){
		if(n%i==0){
			st.insert(i);
			st.insert(n/i);
		}
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll a,b; scanf("%lld%lld",&a,&b);
		ll c=a-b;
		divisors(c);
		vector<ll>v(st.begin(),st.end());
		ll idx=lower_bound(v.begin(),v.end(),b)-v.begin();
		if(v[idx]==b){idx++;}
		ll sz=v.size();
		printf("Case %lld: ",T);
		if(idx==sz){
			printf("impossible\n");
		}
		else{
			for(ll i=idx; i<sz; i++){
				printf("%lld",v[i]);
				if(i!=(sz-1)){printf(" ");}
			}
			printf("\n");
		}
		st.clear();
	}
	return 0;
}

