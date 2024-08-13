//链接：https://codeforces.com/problemset/problem/822/D
// 2024-8-13

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll mod=1e9+7;
ll t,l,r;

void f(){
	vector<int> prime(r+10);
	vector<ll> dp(r+10);
	iota(prime.begin(),prime.end(),0);
	
	for(ll i=2;i*i<=r;i++){
		if(prime[i]!=i)
		   continue;
		for(ll j=i*i;j<=r;j+=i){
			if(prime[j]==j){             //******************
				prime[j]=i;
			}
		}   	
	}
	
	dp[0]=dp[1]=0;          //***********************
	for(ll x=2;x<=r;x++){
		ll n=x/prime[x];
		ll y=prime[x];
		dp[x]=(dp[n]+x*(y-1)/2)%mod;
	}
	
	ll ans=0;
	ll base=1;
	for(ll x=l;x<=r;x++){
		ans=(ans+base*dp[x]%mod)%mod;
		base=base*t%mod;
	}
	
	cout<<ans<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t>>l>>r;
	f();
	
	return 0;
} 

/*
7 2444902 2613424


*/
