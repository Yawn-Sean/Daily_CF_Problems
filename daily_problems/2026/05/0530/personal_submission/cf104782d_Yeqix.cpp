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
		if (l >= x && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		Info res;
		if (x < m) {
			res = rangeQuery(2 * p, l, m, x, y);
			if (y > m) {
				res = res + rangeQuery(2 * p + 1, m, r, x, y);
			}
		} else if (y > m) {
			res = rangeQuery(2 * p + 1, m, r, x, y);
		}
		return res;
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

int n;
vector<i64> a, b;
vector<i64> pre;
struct Info {
	i64 l, r;
	i64 sum;

	Info(): l(0), r(0), sum(0) {}
	Info(int L, int R, i64 S): l(L), r(R), sum(S) {}
};

Info operator+(const Info& L, const Info& R) {
	Info res;
	res.l = min(L.l, R.l);
	res.r = max(L.r, R.r);
	if (L.r <= R.l) {
		res.sum = max(R.sum, L.sum + pre[R.r + 1] - pre[R.l]);
	} else {
		res.sum = max(L.sum, R.sum + pre[L.r + 1] - pre[L.l]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	a.resize(n), b.resize(n), pre.resize(n + 1);
	for (auto& x : a) {
		cin >> x;
	}
	for (auto& x : b) {
		cin >> x;
	}

	vector<Info> f(n);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + b[i] - a[i];
		f[i] = Info(i, i, b[i]);
	}

	SegmentTree<Info> st(f);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;

		cout << st.rangeQuery(l, r).sum << "\n";
	}
	return 0;
}