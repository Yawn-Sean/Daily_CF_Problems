#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
	ll d, mod;
	cin >> d >> mod;
	ll maxbit = 0;
	for (int i = 0; i <= 63; i++) {
		if (d & (1LL << i)) {
			maxbit = i;
		}
	}
	vector<ll> cnt(maxbit + 1);
	for (int i = 0; i <= maxbit; i++) {
		if (i == maxbit) {
			cnt[i] = d - (1LL << i) + 1LL;
		} else {
			cnt[i] = (1LL << i);
		}
		cnt[i] %= mod;
	}
	ll ans = 1;
	for (int i = 0; i <= maxbit; i++) {
		ans *= (cnt[i] + 1LL);
		ans %= mod;
	}
	ans = (ans - 1LL + mod) % mod;
	cout << ans << endl;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
