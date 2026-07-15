#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> tmp;
		long long cur = 0;

		while (n --) {
			int x; cin >> x;
			cur += x;

			if (tmp.empty() || tmp.back() < x) tmp.emplace_back(x);
			else {
				int pos = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
				tmp[pos] = x;
			}

			int l = tmp.size();

			if (l > tmp.back()) cout << cur + 1ll * (l + l + k - 1) * k / 2 << ' ';
			else cout << cur + 1ll * l * k << ' ';
		}

		cout << '\n';
	}

	return 0;
}