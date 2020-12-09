#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1e6;

int main(){

    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	double a=0;
	vector<double>v(N+50);
    for(ll i=1; i<=N; i++){
		a=a+log10(i);
		v[i]=a;
	}
	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll n,b; scanf("%lld%lld",&n,&b);
		ll res=(v[n]/log10(b))+1;
		printf("Case %lld: %lld\n",T,res);
	}
    return 0;
}

