#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll n,k;
	cin >> n >> k;
	vector<ll> arr(n);
	for(auto &x : arr) cin >> x;
	ll ans = k;
	for(int i = 0; i < n; ++i){
		ll mx = k;
		for(int j = i,k = 0; j < n; ++k,j += k){
			mx += arr[j];
			ans = max(ans,mx);
			if(mx < 0) break;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	cout << flush;
	return 0;
}