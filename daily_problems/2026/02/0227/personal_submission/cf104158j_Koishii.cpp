#include <bits/stdc++.h>
using namespace std;

struct Segtree {
	int n;
	struct ST {
		int l, r;
		long long mx;
	};

	std::vector<ST> t;

	Segtree() {}
	Segtree(int _n) {
		n = _n;
		t.assign((n << 2) + 2, {});
		build(1, 1, n);
	}

	void build(int p, int l, int r) {
		t[p] = { l,r };
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
		p.mx = x;
	}

	void pushup(ST& p, ST& pl, ST& pr) {
		p.mx = std::max(pl.mx, pr.mx);
	}

	void build(ST& p, int i) {

	}
};

void soviet() {
	int n, m, k; std::cin >> n >> m >> k;

	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++) std::cin >> a[i];

	std::sort(a.begin() + 1, a.end());

	Segtree t(k + 1);

	while (m--) {
		int l, r, k; std::cin >> l >> r >> k;
		l--;
		if (l >= 1) t.modify(l, l, t.query(l, l).mx + k);
		t.modify(r, r, t.query(r, r).mx - k);
		int mx = t.query(1, k).mx;
		int id = std::lower_bound(a.begin() + 1, a.end(), mx) - a.begin();
		std::cout << n - id + 1 << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
