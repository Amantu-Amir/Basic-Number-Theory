#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e3;

bool cmp(pair<ll,ll>&a, pair<ll,ll>&b){
	if(a.first==b.first){return a.second>b.second;}
	return a.first<b.first;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	vector<pair<ll,ll>>v;
	for(ll i=1; i<=N; i++){
		ll srt=sqrt(i+1),cnt=0;
		for(ll j=1; j<=srt; j++){
			if(i%j==0){
				if(j==(i/j)){cnt++;}
				else{cnt+=2;}
			}
		}
		v.pb({cnt,i});
	}
	sort(v.begin(),v.end(),cmp);
	ll t,a; cin>>t;
	for(ll T=1; T<=t; T++){
		scanf("%lld",&a);
		printf("Case %lld: %lld\n",T,v[a-1].second);
	}
	
	return 0;
}

