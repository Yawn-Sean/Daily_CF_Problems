#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll quickPow(ll x,ll n,ll mod){
	ll ans = 1;
	while(n){
		if(n & 1){
			ans = ans * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}


void solve(){
	int n,x,k;
	int mod = 1e9 + 7;
	cin >> n >> x >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	if(k){
		int sum = (n - 1) * quickPow(2,k,mod) % mod;
		cout << ((x - 1) * quickPow(x,mod - 2,mod) % mod * sum % mod + 1) % mod;

	}else{
		int exp = 1;
		for(int i = 1; i < n; ++i) if(arr[i] != arr[i - 1]) exp += 1;
		cout << exp;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}