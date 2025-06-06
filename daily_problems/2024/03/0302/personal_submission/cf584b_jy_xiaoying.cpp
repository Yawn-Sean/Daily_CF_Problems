#include<bits/stdc++.h> 

using namespace std;

//链接：https://codeforces.com/problemset/problem/584/B
//日期： 2024-3-2 
//格式化： ctrl+shift+ a

const int mod=1e9+7;
typedef long long ll;
ll n; 

ll q_pow(ll x,ll y){  // x^y
	ll ans=1;
	while(y){
		if(y & 1) ans=(ans*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	ll ans=q_pow(3,3*n);
	ans=(ans+mod-q_pow(7,n))%mod;
	cout<<ans<<endl;

	return 0;
}


