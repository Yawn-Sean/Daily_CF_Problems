#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int inv2 = (mod + 1) >> 1;
std::vector<int> a;

struct Segtree {
	int n;
	struct ST {
		int l, r;
		bool ok;
		int len;
		long long prob, ans;
	};

	std::vector<ST> t;

	Segtree() {}
	Segtree(int _n) {
		n = _n;
		t.assign((n << 2) + 2, {});
		t[0].prob = 2;
		build(1, 1, n);
	}

	void build(int p, int l, int r) {
		t[p] = { l,r };
		t[p].prob = t[p >> 1].prob * inv2 % mod;
		if (l == r) { build(t[p], l); return; }
		int mid = l + r >> 1;
		build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
		pushup(t[p], t[p << 1], t[p << 1 | 1]);
	}

	void modify(int p, int l, int r, long long x) {
		if (l <= t[p].l && r >= t[p].r) { update(t[p], x); return; }
		pushdown(t[p], t[p << 1], t[p << 1 | 1]);
		int mid = t[p].l + t[p].r >> 1;
		if (l <= mid) modify(p << 1, l, r, x);
		if (r > mid) modify(p << 1 | 1, l, r, x);
		pushup(t[p], t[p << 1], t[p << 1 | 1]);
	}

	ST query(int p, int l, int r) {
		if (l <= t[p].l && r >= t[p].r) { return t[p]; }
		pushdown(t[p], t[p << 1], t[p << 1 | 1]);
		int mid = t[p].l + t[p].r >> 1;
		if (r <= mid) return query(p << 1, l, r);
		if (l > mid) return query(p << 1 | 1, l, r);
		ST pl = query(p << 1, l, r), pr = query(p << 1 | 1, l, r), ans;
		pushup(ans, pl, pr);
		return ans;
	}

	void modify(int l, int r, long long x) { modify(1, l, r, x); }

	ST query(int l, int r) { return query(1, l, r); }

	void pushdown(ST& p, ST& pl, ST& pr) {

	}

	void update(ST& p, long long x) {

	}

	void pushup(ST& p, ST& pl, ST& pr) {
		if (pl.ok && pr.ok && a[pl.r] <= a[pr.l]) {
			p.ok = true;
			p.len = pl.len + pr.len;
			p.ans = p.len * p.prob % mod;
		}
		else {
			p.ok = false;
			p.len = 0;
			p.ans = (pl.ans + pr.ans) % mod;
		}
	}

	void build(ST& p, int i) {
		p.ok = 1;
		p.len = 1;
		p.ans = p.prob;
	}
};

void soviet() {
	int n, q; std::cin >> n >> q;
	a.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	Segtree t(n);

	while (q--) {
		int p, x; std::cin >> p >> x;
		a[p] = x;
		t.modify(p, p, x);
		std::cout << t.query(1, n).ans << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
