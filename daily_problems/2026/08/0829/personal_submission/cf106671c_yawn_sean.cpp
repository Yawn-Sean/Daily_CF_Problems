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

	int n, mod = 998244353;
	cin >> n;

	int cur = 0;
	deque<int> que;
	bool flg = true;

	while (n --) {
		int x;
		cin >> x;
		cur = (cur + x) % mod;
		que.emplace_back(x);
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i ++) {
		int t;
		cin >> t;

		if (t == 1) {
			int v; cin >> v;
			if (flg) que.emplace_back(v);
			else que.emplace_front(v);
			cur = (cur + v) % mod;
		}
		else if (t == 2) {
			if (flg) {
				cur -= que.back();
				que.pop_back();
			}
			else {
				cur -= que.front();
				que.pop_front();
			}
			cur = (cur % mod + mod) % mod;
		}
		else if (t == 3) flg = !flg;
		else if (t == 4) {
			cur = cur * 2 % mod;
			if (que.size() <= q) {
				vector<int> tmp(que.begin(), que.end());
				que.insert(que.end(), tmp.begin(), tmp.end());
			}
		}
		else cout << cur << '\n';
	}

	return 0;
}