#include <bits/stdc++.h>
using namespace std;


template<typename T>
struct Fenwick {
	int n;
	std::vector<T> t;

	explicit Fenwick(int _n = 0) : n(_n) {
		t.assign(_n + 1, T{});
	}

	void add(int i, const T& x) {
		while (i <= n) {
			t[i] += x;
			i += i & -i;
		}
	}

	T sum(int i) {
		T ans = 0;
		while (i) {
			ans += t[i];
			i -= i & -i;
		}
		return ans;
	}


	int kth(T k) {
		int x = 0;
		T ans = 0;
		for (int i = std::log2(n); i >= 0; i--) {
			int nx = x + (1 << i);
			if (nx <= n && ans + t[nx] < k) {
				x = nx;
				ans += t[x];
			}
		}
		return x + 1;
	}

	T sum(int l, int r) { return sum(r) - sum(l - 1); }
	T query(int i) { return sum(i); }
	T query(int l, int r) { return sum(l, r); }
};

struct Segtree {
	int n;
	struct ST {
		int l, r;
		int mx;
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
	int n; std::cin >> n;
	std::vector<int> nums(n + 1);
	for (int i = 1; i <= n; i++) std::cin >> nums[i];

	Fenwick<int> fen(n);
	for (int i = 1; i <= n; i++) fen.add(i, 1);

	std::vector<int> p(n + 1);
	for (int i = n; i >= 1; i--) {
		p[i] = fen.kth(nums[i]);
		fen.add(p[i], -1);
	}

	Segtree t(n + 1);
	for (int i = 1; i <= n; i++) {
		t.modify(p[i], p[i], t.query(1, p[i]).mx + 1);
		std::cout << t.query(1, n).mx << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
