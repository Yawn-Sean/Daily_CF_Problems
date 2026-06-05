#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int inf = INT_MAX;

template <class Info, class Tag>
struct LazySegmentTree {
	int n;
	vector<Info> info;
	vector<Tag> tag;
	LazySegmentTree() : n(0) {}
	LazySegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
	template <class T>
	LazySegmentTree(vector<T> init_) {
		init(init_);
	}
	void init(int n_, Info v_ = Info()) { init(vector(n_, v_)); }
	template <class T>
	void init(vector<T> init_) {
		n = init_.size();
		info.assign(4 << __lg(n), Info());
		tag.assign(4 << __lg(n), Tag());
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
	void apply(int p, const Tag& v) {
		info[p].apply(v);
		tag[p].apply(v);
	}
	void push(int p) {
		apply(2 * p, tag[p]);
		apply(2 * p + 1, tag[p]);
		tag[p] = Tag();
	}
	void modify(int p, int l, int r, int x, const Info& v) {
		if (r - l == 1) {
			info[p] = v;
			return;
		}
		int m = (l + r) / 2;
		push(p);
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
		push(p);
		return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
	}
	Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
	void rangeApply(int p, int l, int r, int x, int y, const Tag& v) {
		if (l >= y || r <= x) {
			return;
		}
		if (l >= x && r <= y) {
			apply(p, v);
			return;
		}
		int m = (l + r) / 2;
		push(p);
		rangeApply(2 * p, l, m, x, y, v);
		rangeApply(2 * p + 1, m, r, x, y, v);
		pull(p);
	}
	void rangeApply(int l, int r, const Tag& v) { return rangeApply(1, 0, n, l, r, v); }
	void half(int p, int l, int r) {
		if (info[p].act == 0) {
			return;
		}
		if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
			apply(p, { -(info[p].min + 1) / 2});
			return;
		}
		int m = (l + r) / 2;
		push(p);
		half(2 * p, l, m);
		half(2 * p + 1, m, r);
		pull(p);
	}
	void half() { half(1, 0, n); }

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
		push(p);
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
		push(p);
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

	void maintainL(int p, int l, int r, int pre) {
		if (info[p].difl > 0 && info[p].maxlowl < pre) {
			return;
		}
		if (r - l == 1) {
			info[p].max = info[p].maxlowl;
			info[p].maxl = info[p].maxr = l;
			info[p].maxlowl = info[p].maxlowr = -inf;
			return;
		}
		int m = (l + r) / 2;
		push(p);
		maintainL(2 * p, l, m, pre);
		pre = max(pre, info[2 * p].max);
		maintainL(2 * p + 1, m, r, pre);
		pull(p);
	}
	void maintainL() { maintainL(1, 0, n, -1); }
	void maintainR(int p, int l, int r, int suf) {
		if (info[p].difr > 0 && info[p].maxlowr < suf) {
			return;
		}
		if (r - l == 1) {
			info[p].max = info[p].maxlowl;
			info[p].maxl = info[p].maxr = l;
			info[p].maxlowl = info[p].maxlowr = -inf;
			return;
		}
		int m = (l + r) / 2;
		push(p);
		maintainR(2 * p + 1, m, r, suf);
		suf = max(suf, info[2 * p + 1].max);
		maintainR(2 * p, l, m, suf);
		pull(p);
	}
	void maintainR() { maintainR(1, 0, n, -1); }
};

struct Tag {
	i64 lazy;

	Tag(): lazy(0LL) {}
	Tag(i64 v): lazy(v) {}

	void apply(const Tag& t) {
		lazy += t.lazy;
	}
};

struct Info {
	i64 sum, len;

	Info(): sum(0LL), len(1LL) {}
	Info(i64 v, i64 l = 1): sum(v), len(l) {}

	void apply(const Tag& t) {
		sum += t.lazy * len;
	}
};

Info operator+(const Info& a, const Info& b) {
	return Info(a.sum + b.sum, a.len + b.len);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;

	LazySegmentTree<Info, Tag> x(n + 10), y(n + 10);
	x.rangeApply(1, n + 1, Tag(1));

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			array<i64, 2> fst = {x.rangeQuery(1, l + 1).sum, y.rangeQuery(1, l + 1).sum};
			array<i64, 2> snd = {x.rangeQuery(1, r + 1).sum, y.rangeQuery(1, r + 1).sum};
			if (fst[0] == snd[0]) {
				x.rangeApply(l + 1, r + 1, Tag(1)), y.rangeApply(l + 1, r + 1, Tag(-1));
				x.rangeApply(r + 1, r + 2, Tag(-(r - l))), y.rangeApply(r + 1, r + 2, Tag(r - l));
			} else {
				x.rangeApply(l + 1, r + 1, Tag(-1)), y.rangeApply(l + 1, r + 1, Tag(1));
				x.rangeApply(r + 1, r + 2, Tag(r - l)), y.rangeApply(r + 1, r + 2, Tag(-(r - l)));
			}
		} else {
			int v;
			cin >> v;
			cout << x.rangeQuery(1, v + 1).sum << " " << y.rangeQuery(1, v + 1).sum << "\n";
		}
	}
	return 0;
}