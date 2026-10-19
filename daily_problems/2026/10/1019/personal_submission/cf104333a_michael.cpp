#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	ll ans = 0;
	for(int i = 0,a1,a0,b1,b0; i < 32; ++i){
		a1 = b1 = 0;
		for(const auto &x : a) a1 += (x >> i) & 1;
		for(const auto &x : b) b1 += (x >> i) & 1;
		a0 = n - a1;
		b0 = n - b1;
		ans = (ans + (1ll * a0 * b1 + 1ll * a1 * b0) * (1ll << i)) % MOD;
	}
	for(int i = 1; i < n; ++i){
		ans = (ans * i) % MOD;
	}
	cout << ans << '\n';
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