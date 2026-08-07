#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

template <typename T>
std::vector<int> prep(const T& p) {
	int n = static_cast<int>(p.size());
	std::vector<int> pi(n, 0);
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j != 0 && p[j] != p[i]) {
			j = pi[j - 1];
		}
		if (p[j] == p[i]) {
			++j;
		}
		pi[i] = j;
	}
	return pi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y, z;
	cin >> n >> x >> y >> z;

	string s;
	cin >> s;

	auto v1 = prep(s);

	reverse(s.begin(), s.end());
	auto v2 = prep(s);
	reverse(v2.begin(), v2.end());

	long long ans = 0, cur = -3e18;

	for (int i = n - 2; i >= 0; i --) {
		cur += z;
		if (v2[i + 1] > 0) cur = max(cur, 1ll * y * v2[i + 1]);
		if (v1[i] > 0) ans = max(ans, cur + 1ll * x * v1[i]);
	}

	cout << ans;

	return 0;
}