#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
 
vector<pair<ll,ll>>v;
 
void factors(ll n){
	ll srt=sqrt(n+1);
	for(ll i=2; i<=srt; i++){
		ll cnt=0;
		while(n%i==0){
			n/=i; cnt++;
		}
		if(cnt){
			v.pb({i,cnt});
		}
	}
	if(n>1){
		v.pb({n,1});
	}
}
 
 
int main(){
 
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
	ll t; cin>>t;
	while(t--){
		ll p,q; cin>>p>>q;
		if(p%q!=0){
			cout<<p<<"\n";continue;
		}
		factors(q);
		ll sz=v.size(),temp=p,res=1;
		for(ll i=0; i<sz; i++){
			ll cnt=0,a=v[i].first;
			while(temp%a==0){
				temp/=a; cnt++;
			}
			cnt-=(v[i].second-1);
			ll b=pow(a,cnt);
			res=max(res,p/b);
		}
		cout<<res<<"\n"; v.clear();
	}
	
	return 0;
}
