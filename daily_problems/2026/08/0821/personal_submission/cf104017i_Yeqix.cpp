#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
template <class Info>
struct SegmentTree {
	int n;
	vector<Info> info;
	SegmentTree() : n(0) {}
	SegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
	template <class T>
	SegmentTree(vector<T> init_) {
		init(init_);
	}
	void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
	template <class T>
	void init(vector<T> init_) {
		n = init_.size();
		info.assign(4 << __lg(n), Info());
		function<void(int, int, int)> build = [&](int p, int l, int r) {
			if (r - l == 1) {
				info[p] = init_[l];
				return;
			}
			int m = (l + r) / 2;
			build(2 * p, l, m);
			build(2 * p + 1, m, r);
			pull(p);
		};
		build(1, 0, n);
	}
	void pull(int p) { info[p] = info[2 * p] + info[2 * p + 1]; }
	void modify(int p, int l, int r, int x, const Info& v) {
		if (r - l == 1) {
			info[p] = v;
			return;
		}
		int m = (l + r) / 2;
		if (x < m) {
			modify(2 * p, l, m, x, v);
		} else {
			modify(2 * p + 1, m, r, x, v);
		}
		pull(p);
	}
	void modify(int p, const Info& v) { modify(1, 0, n, p, v); }
	Info rangeQuery(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) {
			return Info();
		}
		if (l >= x && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
	}
	Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
	template <class F>
	int findFirst(int p, int l, int r, int x, int y, F&& pred) {
		if (l >= y || r <= x) {
			return -1;
		}
		if (l >= x && r <= y && !pred(info[p])) {
			return -1;
		}
		if (r - l == 1) {
			return l;
		}
		int m = (l + r) / 2;
		int res = findFirst(2 * p, l, m, x, y, pred);
		if (res == -1) {
			res = findFirst(2 * p + 1, m, r, x, y, pred);
		}
		return res;
	}
	template <class F>
	int findFirst(int l, int r, F&& pred) {
		return findFirst(1, 0, n, l, r, pred);
	}
	template <class F>
	int findLast(int p, int l, int r, int x, int y, F&& pred) {
		if (l >= y || r <= x) {
			return -1;
		}
		if (l >= x && r <= y && !pred(info[p])) {
			return -1;
		}
		if (r - l == 1) {
			return l;
		}
		int m = (l + r) / 2;
		int res = findLast(2 * p + 1, m, r, x, y, pred);
		if (res == -1) {
			res = findLast(2 * p, l, m, x, y, pred);
		}
		return res;
	}
	template <class F>
	int findLast(int l, int r, F&& pred) {
		return findLast(1, 0, n, l, r, pred);
	}
};

struct Info {
	i64 mn;

	Info(): mn(inf) {}
	Info(i64 v): mn(v) {}
};

Info operator+(const Info & a, const Info & b) {
	return Info(min(a.mn, b.mn));
}

void solve() {
	i64 n, a, b;
	cin >> n >> a >> b;
	vector<i64> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	vector<i64> dp(n + 1, inf);
	dp[a] = 0;

	auto get = [&](int vis)->bool{
		int ans = 0;
		SegmentTree<Info> st(dp);
		vector<vector<i64>> hc(n + 1);
		for (int i = 1; i <= n; i++) {
			for (const auto&v : hc[i]) {
				st.modify(v, Info());
			}

			i64 val = st.rangeQuery(max(1LL, i - p[i]), i).mn;
			if (val + 1 < dp[i]) {
				dp[i] = val + 1;
				ans |= vis;
			}

			st.modify(i, Info(dp[i]));
			if (i + p[i] + 1 <= n) {
				hc[i + p[i] + 1].push_back(i);
			}
		}

		return ans;
	};

	int vis = 1;
	while (vis) {
		vis = 0;
		for (int i = 0; i < 2; i++) {
			vis |= get(i);
			reverse(dp.begin() + 1, dp.end());
			reverse(p.begin() + 1, p.end());
		}
	}

	cout << dp[b] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}