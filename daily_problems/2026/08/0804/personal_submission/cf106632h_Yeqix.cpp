#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	int n;
	cin >> n;
	multiset<i64> st;
	for (int i = 1; i <= n; i++) {
		i64 x;
		cin >> x;
		st.insert(x);
	}

	vector<array<i64, 2>> w(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i][0];
		w[i][1] = i;
	}

	sort(w.begin() + 1, w.end(), [&](auto x, auto y) {
		return x[0] > y[0];
	});

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		auto it = st.upper_bound(w[i][1]);
		if (it != st.begin()) {
			ans += w[i][0];
			st.erase(prev(it));
		}
	}

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}