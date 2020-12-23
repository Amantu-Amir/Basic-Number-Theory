#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e6;

ll calc(ll n){
	ll a=5,b=0;
	while(a<=n){
		b+=(n/a);
		a*=5;
	}
	return b;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll n; scanf("%lld",&n);
		ll L=5,R=n*5,res,ok=0;
		while(L<=R){
			ll mid=(L+R)/2;
			ll zeros=calc(mid);
			if(zeros==n and mid%5==0){
				ok=1; res=mid; 
				break;
			}
			if(zeros<n){
				L=mid+1;
			}
			else{
				R=mid-1;
			}
			//cout<<L<<" "<<R<<"\n";
		}
		if(ok==1){
			printf("Case %lld: %lld\n",T,res);
		}
		else{
			printf("Case %lld: impossible\n",T);
		}
	}

	return 0;
}

