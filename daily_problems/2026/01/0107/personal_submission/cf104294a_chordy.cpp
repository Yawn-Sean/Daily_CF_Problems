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
	int n, q;
	cin >> n >> q;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto &v : a) for (auto &i : v) cin >> i;

	vector<vector<int>> minr(n + 1, vector<int>(n * n + 1, inf));
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			for (int j = 0; j + l - 1 < n; j++) {
				minr[l][a[i][j]] = min(a[i + l - 1][j + l - 1], minr[l][a[i][j]]);
			}
		}
	}
	for (int l = 1; l <= n; l++) {
		for (int i = n * n - 1; i >= 0; i--) {
			minr[l][i] = min(minr[l][i + 1], minr[l][i]);
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		for (int l = n; l >= 1; l--) {
			if (minr[l][x] <= y) {
				cout << l * l << '\n';
				break;
			}
		}
	}
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);

	solve();
	
	return 0;
}