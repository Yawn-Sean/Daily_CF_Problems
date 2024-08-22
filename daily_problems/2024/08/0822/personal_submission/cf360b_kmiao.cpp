#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define endl '\n'
using ll = long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}

	auto check = [&](ll x) -> bool {
		vi dp(n + 1, n + 1);
		iota(begin(dp), end(dp), 0);
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (abs(a[j] - a[i]) <= x * (j - i)) dp[j] = min(dp[j], dp[i] + j - i - 1);
			}
		}
		int mn = n;
		for (int i = 0; i < n; i++) {
			mn = min(mn, n - 1 - (i - dp[i]));
		}
		return mn <= k;
	};

	ll l = 0, r = 2 * MOD;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
