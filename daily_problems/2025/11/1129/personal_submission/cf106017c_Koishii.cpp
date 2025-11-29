#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long qmi(long long a, long long b, long long p) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans % p;
}

struct Line {
	int a, b;
	Line(int _a = 1, int _b = 0) : a(_a), b(_b) {}

	Line operator * (const Line &f) const {
		return Line((1LL * a * f.a) % mod, (1LL * a * f.b + b) % mod);
	}

	int operator * (const int &x) const {
		return (1LL * a * x + b) % mod;
	}
};

struct Segtree {
	int n;
	struct ST {
		int l, r;
		Line line;
		bool has_lazy;
	};

	std::vector<ST> t;

	Segtree() {}
	Segtree(int _n) {
		n = _n;
		t.assign((n << 2) + 2, {});
		build(1, 1, n);
	}

	void build(int p, int l, int r) {
		t[p] = {l, r, Line(1, 0), false};
		if (l == r) { 
			build(t[p], l); 
			return; 
		}
		int mid = l + r >> 1;
		build(p << 1, l, mid); 
		build(p << 1 | 1, mid + 1, r);
		pushup(t[p], t[p << 1], t[p << 1 | 1]);
	}

	void modify(int p, int l, int r, const Line& x) {
		if (l <= t[p].l && r >= t[p].r) { 
			update(t[p], x); 
			return; 
		}
		pushdown(p);
		int mid = t[p].l + t[p].r >> 1;
		if (l <= mid) modify(p << 1, l, r, x);
		if (r > mid) modify(p << 1 | 1, l, r, x);
		pushup(t[p], t[p << 1], t[p << 1 | 1]);
	}

	ST query(int p, int l, int r) {
		if (l <= t[p].l && r >= t[p].r) { 
			return t[p]; 
		}
		pushdown(p);
		int mid = t[p].l + t[p].r >> 1;
		if (r <= mid) return query(p << 1, l, r);
		if (l > mid) return query(p << 1 | 1, l, r);
		ST pl = query(p << 1, l, r), pr = query(p << 1 | 1, l, r), ans;
		pushup(ans, pl, pr);
		return ans;
	}

	void modify(int l, int r, const Line& x) { 
		if (l <= r) modify(1, l, r, x); 
	}

	ST query(int l, int r) { 
		return query(1, l, r); 
	}

	void pushdown(int p) {
		if (t[p].has_lazy && t[p].l != t[p].r) {
			update(t[p << 1], t[p].line);
			update(t[p << 1 | 1], t[p].line);
			t[p].line = Line(1, 0);
			t[p].has_lazy = false;
		}
	}

	void update(ST& p, const Line& x) {
		p.line = x * p.line;
		p.has_lazy = true;
	}

	void pushup(ST& p, const ST& pl, const ST& pr) {

	}

	void build(ST& p, int i) {
		p.line = Line(1, 0);
		p.has_lazy = false;
	}
};

void soviet() {
	int q; std::cin >> q;

	Segtree t(q + 1);

	int pt = 0;
	std::vector<int> idxs(q);
	std::vector<int> val(q + 1);

	for (int i = 0; i < q; i++) {
		int op; std::cin >> op;
		if (op == 1) {
			int x; std::cin >> x;
			idxs[i] = ++pt;
			val[pt] = x;
			t.modify(pt, pt, Line(1, 0));
		}
		else if (op == 2) { // add
			int x; std::cin >> x;
			x = (x % mod + mod) % mod;
			t.modify(1, pt, Line(1, x));
		}
		else if (op == 3) { // mul
			int p, q_val; 
			std::cin >> p >> q_val;
			int x = 1LL * p * qmi(q_val, mod - 2, mod) % mod;
			x = (x % mod + mod) % mod;
			t.modify(1, pt, Line(x, 0));
		}
		else {
			int idx; std::cin >> idx;
			int pos = idxs[idx - 1];
			int result = t.query(pos, pos).line * val[pos];
			cout << result << '\n';
		}
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
