#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
/**   树状数组（Fenwick 新版）
 *    2023-12-28: https://codeforces.com/contest/1915/submission/239262801
**/
template <typename T>
struct Fenwick {
	int n;
	std::vector<T> a;

	Fenwick(int n_ = 0) {
		init(n_);
	}

	void init(int n_) {
		n = n_;
		a.assign(n, T{});
	}

	void add(int x, const T &v) {
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] = a[i - 1] + v;
		}
	}

	T sum(int x) {
		T ans{};
		for (int i = x; i > 0; i -= i & -i) {
			ans = ans + a[i - 1];
		}
		return ans;
	}

	T rangeSum(int l, int r) {
		return sum(r) - sum(l);
	}

	int select(const T &k) {
		int x = 0;
		T cur{};
		for (int i = 1 << std::__lg(n); i; i /= 2) {
			if (x + i <= n && cur + a[x + i - 1] <= k) {
				x += i;
				cur = cur + a[x - 1];
			}
		}
		return x;
	}
};
void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	Fenwick<int> f(n * 2);
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (a[i] >= i) {
			f.add(a[i] + n, 1);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int en = a[i];
		if (a[i] < i) {
			en = a[i] + n;
		}
		ans[a[i]] = en - i - f.rangeSum(0, en);
		f.add(en, 1);
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
