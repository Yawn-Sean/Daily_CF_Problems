#include <bits/stdc++.h>
using namespace std;

struct Segtree {
	int n;
	struct ST {
		int l, r;
		int gd;
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

	void modify(int l, int r, long long x) { modify(1, l, r, x); }

	ST query(int l, int r) { return query(1, l, r); }

	void pushdown(ST& p, ST& pl, ST& pr) {

	}

	void update(ST& p, long long x) {
		p.gd = x;
	}

	void pushup(ST& p, ST& pl, ST& pr) {
		p.gd = __gcd(pl.gd, pr.gd);
	}

	void build(ST& p, int i) {
		p.gd = 0;
	}
};

const int N = 200005;
int f[N];
void init() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			f[j]++;
		}
	}
}

void soviet() {
	int n, q; std::cin >> n >> q;
	f[0] = n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	Segtree t(n + 1);
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i - 1]) t.modify(i, i, i - 1);
	}
	std::cout << f[t.query(1, n).gd] << '\n';
	while (q--) {
		int pos, val; std::cin >> pos >> val;
		a[pos] = val;
		if (pos > 1) {
			if (a[pos] < a[pos - 1]) {
				t.modify(pos, pos, pos - 1);
			}
			else {
				t.modify(pos, pos, 0);
			}
		}
		if (pos < n) {
			if (a[pos + 1] < a[pos]) {
				t.modify(pos + 1, pos + 1, pos);
			}
			else {
				t.modify(pos + 1, pos + 1, 0);
			}
		}
		std::cout << f[t.query(1, n).gd] << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	init();
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
