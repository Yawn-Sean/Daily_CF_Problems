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

	string s;
	cin >> s;

	int n = s.size();

	int q;
	cin >> q;

	auto prod = [&] (vector<int> &v1, vector<int> &v2) -> vector<int> {
		vector<int> res;
		for (auto &x: v1) res.emplace_back(v2[x]);
		return res;
	};

	while (q --) {
		int k, d;
		cin >> k >> d;

		vector<int> p(n), tmp;
		iota(p.begin(), p.end(), 0);

		for (int i = 0; i < d; i ++) {
			for (int j = i; j < k; j += d) {
				tmp.emplace_back(j);
			}
		}

		for (int i = 0; i < k; i ++) p[tmp[i]] = i;

		for (int i = 0; i < n; i ++) p[i] = (p[i] + n - 1) % n;

		vector<int> res(n);
		iota(res.begin(), res.end(), 0);

		int steps = n - k + 1;

		for (int i = 0; i < 20; i ++) {
			if (steps >> i & 1) res = prod(res, p);
			p = prod(p, p);
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i ++) ans[res[i]] = i;

		for (int i = 0; i < n; i ++) {
			if (ans[i] == 0) {
				string ns;
				for (int j = 0; j < n; j ++) {
					ns += s[ans[(i + j) % n]];
				}
				s = ns;
				break;
			}
		}

		cout << s << '\n';
	}

	return 0;
}