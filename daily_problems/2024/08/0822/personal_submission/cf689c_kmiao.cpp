#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const ll INF = (ll)1e18;

const int N = 1'000'000;

void solve() {
	ll m;
	cin >> m;
	vector<ll> a(N + 1);
	for (int i = 2; i <= N; i++) {
		a[i] = pow(i, 3);
	}

	auto check = [&](ll x) -> ll {
		ll res = 0;
		for (int i = 2; i <= N; i++) {
			res += x / a[i];
		}
		return res;
	};

	ll l = 0, r = INF;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid) >= m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (check(r) == m) cout << r << endl;
	else cout << -1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
