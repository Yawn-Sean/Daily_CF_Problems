#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> nodes(n);
	for (auto &[x, s]: nodes) cin >> x >> s;

	int ans = 0, cur = 0, mod = 998244353;
	for (int i = n - 1; i >= 0; i --) {
		ans = (ans + 1ll * (cur + nodes[i].second) * nodes[i].first) % mod;
		cur = (cur * 2 + nodes[i].second) % mod;
	}

	cout << (ans + nodes.back().first + 1) % mod;

	return 0;
}