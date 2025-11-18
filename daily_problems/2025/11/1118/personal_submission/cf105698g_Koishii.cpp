#include <bits/stdc++.h>
using namespace std;

struct Segtree {
	int n;
	struct ST {
		int l, r;
		int dat;
	};

	std::vector<ST>t;

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

	int findMax(int p, int i) {
		if (t[p].l > i) return -1;
		if (t[p].dat >= i) return -1;
		if (t[p].l == t[p].r) return t[p].l;

		int mid = t[p].l + t[p].r >> 1;
		int res = -1;
		if (i > mid) res = findMax(p << 1 | 1, i);
		if (res != -1) return res;
		return findMax(p << 1, i);
	}

	void modify(int l, int r, long long x) { modify(1, l, r, x); }

	ST query(int l, int r) { return query(1, l, r); }

	void pushdown(ST& p, ST& pl, ST& pr) {

	}

	void update(ST& p, int x) {
		p.dat = std::max(p.dat, x);
	}

	void pushup(ST& p, ST& pl, ST& pr) {
		p.dat = std::min(pl.dat, pr.dat);
	}

	void build(ST& p, int i) {
		p.dat = 0;
	}
};

void soviet() {
	int n, q; std::cin >> n >> q;

	Segtree t(n);

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r; std::cin >> l >> r;
			t.modify(l, l, r);
		}
		else {
			int pos; std::cin >> pos;
			int j = t.findMax(1, pos);
			if (j == -1) {
				std::cout << pos + 1 << '\n';
			}
			else {
				std::cout << pos - j + 1 << '\n';
			}
		}
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
