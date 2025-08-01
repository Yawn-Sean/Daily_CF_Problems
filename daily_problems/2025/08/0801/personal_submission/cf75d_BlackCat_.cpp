#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
/**   懒标记线段树（LazySegmentTree）
 *    2023-03-03: https://atcoder.jp/contests/joi2023yo2/submissions/39363123
 *    2023-03-12: https://codeforces.com/contest/1804/submission/197106837
 *    2023-07-17: https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804432
 *    2023-11-12: https://qoj.ac/submission/249505
 *    2024-08-14:  https://ac.nowcoder.com/acm/contest/view-submission?submissionId=70980889&returnHomeType=1&uid=329687984
**/
template<class Info>
struct LazySegmentTree {
	int n;
	std::vector<Info> info;
	LazySegmentTree() : n(0) {}
	LazySegmentTree(int n_, Info v_ = Info()) {
		init(n_, v_);
	}
	template<class T>
	LazySegmentTree(std::vector<T> init_) {
		init(init_);
	}
	void init(int n_, Info v_ = Info()) {
		init(std::vector(n_, v_));
	}
	template<class T>
	void init(std::vector<T> init_) {
		n = init_.size();
		info.assign(4 << std::__lg(n), Info());
		std::function<void(int, int, int)> build = [&](int p, int l, int r) {
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
	void pull(int p) {
		info[p] = info[2 * p] + info[2 * p + 1];
	}
	void modify(int p, int l, int r, int x, const Info &v) {
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
	void modify(int p, const Info &v) {
		modify(1, 0, n, p, v);
	}
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
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
	}

};

struct Info {
	i64 ans = 0;
	i64 sum = 0;
	i64 lmax = 0;
	i64 rmax = 0;
	i64 len = 0;
	i64 llen = 0;
	i64 rlen = 0;
};

Info operator+(const Info &a, const Info &b) {
	if (a.len == 0) {
		return b;
	}
	if (b.len == 0) {
		return a;
	}
	Info ans;
	ans.ans = std::max({a.ans, b.ans, a.rmax + b.lmax});
	ans.sum = a.sum + b.sum;

	ans.lmax = a.lmax;
	ans.llen = a.llen;
	ans.rmax = b.rmax;
	ans.rlen = b.rlen;
	if (ans.lmax < a.sum + b.lmax) {
		ans.lmax = a.sum + b.lmax;
		ans.llen = a.len + b.llen;
	}
	if (ans.rmax < b.sum + a.rmax) {
		ans.rmax = b.sum + a.rmax;
		ans.rlen = b.len + a.rlen;
	}
	ans.len = a.len + b.len;
	return ans;
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<Info> in(n);
	for (int i = 0; i < n; i++) {
		int l;
		std::cin >> l;
		LazySegmentTree<Info> seg(l);
		for (int j = 0; j < l; j++) {
			int x;
			std::cin >> x;
			seg.modify(j, {x, x, x, x, 1, 1, 1});
		}
		in[i] = seg.rangeQuery(0, l);
	}
	LazySegmentTree<Info> seg(m);
	for (int i = 0; i < m; i++) {
		int l;
		std::cin >> l;
		l--;
		seg.modify(i, in[l]);
	}
	std::cout << seg.rangeQuery(0, m).ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
