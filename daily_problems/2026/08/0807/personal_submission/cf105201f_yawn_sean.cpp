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

	string s;
	cin >> s;

	int n = s.size();

	string tmp;
	for (int i = 0; i < n; i ++) {
		if (i) tmp += '|';
		tmp += s[i];
	}

	int ans = n, j = 0;
	vector<int> wing(2 * n - 1, 0);

	for (int i = 0; i < 2 * n - 1; i ++) {
		if (j + wing[j] >= i) wing[i] = min(j + wing[j] - i, wing[2 * j - i]);
		while (i - wing[i] - 1 >= 0 && i + wing[i] + 1 < 2 * n - 1 && tmp[i - wing[i] - 1] == tmp[i + wing[i] + 1]) {
			wing[i] ++;
			if ((i - wing[i]) % 2 == 0) ans --;
		}
		if (i + wing[i] > j + wing[j]) j = i;
	}

	cout << ans;

	return 0;
}