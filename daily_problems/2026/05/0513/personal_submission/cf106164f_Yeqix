#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

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

	int range(int p, int l, int r, int x, i64& Q) {
		if (r - l == 1) {
			if (Q >= info[p].sum1) {
				Q -= info[p].sum1;
				return -1;
			}
			return l;
		}

		int m = (l + r) / 2;
		if (l == x) {
			if (Q >= info[p * 2].sum1) {
				Q -= info[p * 2].sum1;
				return range(p * 2 + 1, m, r, m, Q);
			}
			return range(p * 2, l, m, x, Q);
		}
		if (m <= x) {
			return range(p * 2 + 1, m, r, x, Q);
		}
		int fst = range(p * 2, l, m, x, Q);
		if (fst == -1) {
			return range(p * 2 + 1, m, r, m, Q);
		}
		return fst;
	}
	int range(int l, i64& Q) {return range(1, 0, n, l, Q);}

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
	i64 num;
	i64 sum1, sum2;
	Info(): num(1e16), sum1(0LL), sum2(0LL) {}
	Info(i64 v, i64 v2): num(v), sum1(v), sum2(v2) {}
};

Info operator+(const Info& a, const Info& b) {
	Info res;
	res.num = min(a.num, b.num);
	res.sum1 = a.sum1 + b.sum1;
	res.sum2 = a.sum2 + b.sum2;
	return res;
}

void solve() {
	i64 n, p;
	cin >> n >> p;
	vector<int> hap(1);
	vector<array<i64, 3>> a(n);
	for (int i = 1; i <= n; i++) {
		i64 h, p;
		cin >> h >> p;
		a[i - 1] = {h, p, i};
		hap.push_back(h);
	}

	ranges::sort(hap, greater<i64>());
	hap.erase(unique(hap.begin(), hap.end()), hap.end());
	sort(a.begin(), a.end(), [&](auto x, auto y) {
		return x[0] < y[0];
	});

	SegmentTree<Info> st(n + 1);
	array<i64, 2> ans = {0, 0};
	for (const auto& v : hap) {
		while (!a.empty() && a.back()[0] > v) {
			auto [h, p, id] = a.back();
			st.modify(id, Info(p, h));
			a.pop_back();
		}

		i64 res = 0, per = p;
		int now = 0;
		while (now <= n) {
			int w = st.findFirst(now + 1, n + 1, [&](const Info & f) {
				return f.num <= per;
			});
			if (w == -1) {
				break;
			}
			now = w;
			int last = st.range(now, per);
			if (last == -1) {
				last = n + 1;
			}
			Info q = st.rangeQuery(now, last);
			res += q.sum2;
			now = last;
		}

		if (res >= ans[0]) {
			ans = {res, v};
		}
	}

	cout << ans[0] << " " << ans[1] << "\n";
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
