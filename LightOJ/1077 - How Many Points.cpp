#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e6;

ll gcd(ll a,ll b){
	if(b==0){return a;}
	return gcd(b,a%b);
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		ll x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		ll x=abs(x1-x2),y=abs(y1-y2);
		ll res=gcd(x,y)-1;
		printf("Case %lld: %lld\n",T,res+2);
	}

	return 0;
}

