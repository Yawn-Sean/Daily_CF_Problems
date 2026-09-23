#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Fenwick { // 1_idx
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

const int N = 100005;
int n, q, k;
int a[N], b[N];

int siz;
long long ans[N];

Fenwick<int> fa(N), fb(N);

struct Ask {
	int l, r, k, id;
	bool operator < (const Ask& e2) const {
		if ((l - 1) / siz != (e2.l - 1) / siz) return l < e2.l;
		if (((l - 1) / siz) & 1) return r < e2.r;
		return r > e2.r;
	}
} ask[N];

void add(int i) {
	if (a[i] < N) fa.add(a[i], 1);
	if (b[i] < N) fb.add(b[i], 1);
	
}

void del(int i) {
	if (a[i] < N) fa.add(a[i], -1);
	if (b[i] < N) fb.add(b[i], -1);
}

long long get_ans() {
	long long res = 0;
	int sq = std::sqrt(k);
	for (int i = 1; i <= sq; i++) {
		res += (long long)fa.sum(i, i) * fb.sum(1, k / i);
		res += (long long)fb.sum(i, i) * fa.sum(1, k / i);
	}
	res -= (long long)fa.sum(1, sq) * fb.sum(1, sq);
	return res;
}

void init() {
	siz = std::sqrt(n);
	std::sort(ask + 1, ask + q + 1);
	for (int i = 1, l = 1, r = 0; i <= q; i++) {
		k = ask[i].k;
		while (l > ask[i].l) add(--l);
		while (r < ask[i].r) add(++r);
		while (l < ask[i].l) del(l++);
		while (r > ask[i].r) del(r--);
		ans[ask[i].id] = get_ans();
	}
}

void soviet() {
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	for (int i = 1; i <= q; i++) {
		cin >> ask[i].l >> ask[i].r >> ask[i].k;
		ask[i].id = i;
	}

	init();

	for (int i = 1; i <= q; i++) {
		std::cout << ans[i] << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
