#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 500005;
int a[N], ans[N], last[N];

struct Ask {
	int l, r, id;
	bool operator < (const Ask & e2) const {
		return l > e2.l;
	}
}ak[N];

long long qmi(long long a,long long b,long long p){
	long long ans = 1;
	while(b){
		if(b&1) ans = ans*a%p;
		b>>=1;
		a = a*a%p;
	}
	return ans%p;
}

std::vector<int> primes, minp, maxp;
void sieve(int n = 1e6) {
    minp.resize(n + 1);
    maxp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = maxp[i] = i;
            primes.emplace_back(i);
        }
        for (auto &j : primes) {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
            maxp[i * j] = maxp[i];
        }
    }
}
std::vector<std::pair<int,int>> factorize(int n) {
	std::vector<std::pair<int,int>>ans;
    while (n > 1) {
        int now = minp[n], cnt = 0;
        while (n % now == 0) {
            n /= now;
            cnt++;
        }
        ans.push_back({now, cnt});
    }
    return ans;
}

struct Segtree {
	int n;
	struct ST {
		int l, r;
		long long prod;
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
		p.prod = p.prod * x % mod;
	}

	void pushup(ST& p, ST& pl, ST& pr) {
		p.prod = pl.prod * pr.prod % mod;
	}

	void build(ST& p, int i) {
		p.prod = 1;
	}
};

void soviet() {
	int n, q; std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= q; i++) {
		int l, r; std::cin >> l >> r;
		ak[i] = {l, r, i};
	}

	std::sort(ak + 1, ak + q + 1);

	Segtree t(n);

	for (int i = n, id = 1; id <= q; id++) {
		while (i >= ak[id].l) {
			for (auto &[p, k]: factorize(a[i])) {
				if (last[p]) t.modify(last[p], last[p], qmi(p, mod - 2, mod));
				t.modify(i, i, p);
				last[p] = i;
			}
			i--;
		}
		ans[ak[id].id] = t.query(ak[id].l, ak[id].r).prod;
	}

	for (int i = 1; i <= q; i++) {
		std::cout << ans[i] << ' ';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	sieve(200005);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
