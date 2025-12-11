#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<long long, long long>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	set<pair<long long, long long>> st(pts.begin(), pts.end());

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];
			long long dx = x2 - x1;
			long long dy = y2 - y1;

			if (st.find({x1 + dx - dy, y1 + dx + dy}) != st.end() && st.find({x1 - dy, y1 + dx}) != st.end()) ans ++;
			if (st.find({x1 + dy, y1 - dx}) != st.end() && st.find({x1 + dx + dy, y1 + dy - dx}) != st.end()) ans ++;
		}
	}

	cout << ans / 4;

	return 0;
}