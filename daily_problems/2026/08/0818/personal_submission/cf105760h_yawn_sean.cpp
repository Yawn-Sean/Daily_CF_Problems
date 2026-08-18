#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, s, e;
	cin >> k >> s >> e;

	vector<int> emptys;
	for (int i = 1; i <= k; i ++) {
		if (i != s && i != e) {
			emptys.emplace_back(i);
		}
	}

	cout << 2 * (k - 1) * (k - 1) - 1 << '\n';

	for (int i = k - 1; i >= 1; i --) {
		cout << s << ' ' << e << '\n';
		for (int j = 0; j <= i - 2; j ++) cout << s << ' ' << emptys[k - 3 - j] << '\n';
		for (int j = i - 3; j >= 0; j --) cout << emptys[k - 3 - j] << ' ' << emptys[k - 1 - i] << '\n';
		if (i > 1) cout << e << ' ' << emptys[k - 1 - i] << '\n';
	}

	for (int i = k - 3; i >= 0; i --) {
		cout << emptys[i] << ' ' << s << '\n';
		for (int j = k - 3; j >= i + 1; j --) cout << emptys[i] << ' ' << emptys[j] << '\n';
		cout << emptys[i] << ' ' << e << '\n';
		for (int j = i + 1; j <= k - 3; j ++) cout << emptys[j] << ' ' << e << '\n';
		cout << s << ' ' << e << '\n';
	}

	return 0;
}