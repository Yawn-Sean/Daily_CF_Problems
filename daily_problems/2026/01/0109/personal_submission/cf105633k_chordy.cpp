#include <bits/stdc++.h>
#define int long long
namespace cc {
	using namespace std;
	using i128 = __int128;
	using pii = array<int, 2>;
	constexpr int inf = 1e18;
}
using namespace cc;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (auto &c : s) {
			a[i] = (a[i] << 1) + (c == 'Y');
		}
		p[i] = __builtin_popcount(a[i]);
	}

	if (*max_element(a.begin(), a.end()) == (1 << m) - 1) {
		int p1 = max_element(a.begin(), a.end()) - a.begin();
		int x = -1, p2 = -1;
		for (int i = 0; i < n; i++) {
			if (i == p1) continue;
			if (x < p[i]) {
				x = p[i];
				p2 = i;
			}
		}
		if (p1 > p2) swap(p1, p2);
		cout << p1 + 1 << ' ' << p2 + 1 << '\n';
		return;
	}


	vector<int> dp(1 << m, inf), cnt(1 << m, -1);
	for (int i = 0; i < n; i++) {
		if (p[i] > cnt[a[i]]) {
			dp[a[i]] = i;
			cnt[a[i]] = p[i];
		}
	}

	for (int i = (1 << m) - 1; i >= 0; i--) {
		for (int k = 0; k < m; k++) {
			if (i >> k & 1) continue;
			int j = i | (1 << k);
			if (cnt[i] < cnt[j]) {
				dp[i] = dp[j];
				cnt[i] = cnt[j];
			} else if (cnt[i] == cnt[j]) {
				dp[i] = min(dp[i], dp[j]);
			}
		}
	}

	int mx = -1, p1 = -1, p2 = -1;
	for (int i = 0; i < n; i++) {
		int need = ((1 << m) - 1) ^ a[i];
		if (cnt[need] != -1 && mx < p[i] + cnt[need]) {
			p1 = i;
			p2 = dp[need];
			mx = p[i] + cnt[need];
		}
	}
	if (mx == -1) {
		cout << "No" << '\n'; 
	} else {
		cout << p1 + 1 << ' ' << p2 + 1 << '\n';
	}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);

	solve();
	
	return 0;
}