#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const int N=1e6;

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t; scanf("%lld",&t);
	for(ll T=1; T<=t; T++){
		string a; ll b; 
		cin>>a>>b;
		b=abs(b);
		ll len=a.size();
		if(a[0]=='0'){
			printf("Case %lld: divisible\n",T);
			continue;
		}
		ll temp=0,idx=0;
		if(a[0]=='-'){idx++;}
		while(temp<b and idx<len){
			temp=temp*10+a[idx++]-'0';
		}
		if(temp<b){
			printf("Case %lld: not divisible\n",T);
			continue;
		}
		string ans;
		while(1){
			ans+=(temp/b)+'0';
			temp%=b;
			if(idx>=len){break;}
			temp=temp*10+a[idx++]-'0';
		}
		if(temp!=0){
			printf("Case %lld: not divisible\n",T);
		}
		else{
			printf("Case %lld: divisible\n",T);
		}
	}
	
	return 0;
}

