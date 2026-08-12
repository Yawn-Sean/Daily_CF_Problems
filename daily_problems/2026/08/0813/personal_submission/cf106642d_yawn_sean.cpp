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

	long long a, b;
	cin >> a >> b;

	vector<int> ans;
	a ++;

	while (b) {
		ans.emplace_back(b % a);
		b /= a;
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " \n"[i + 1 == ans.size()];

	return 0;
}