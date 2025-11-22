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

	T sum(int l, int r) {
		return sum(r) - sum(l - 1); 
	}
	T query(int i) { return sum(i); }
	T query(int l, int r) { return sum(l, r); }
};

void soviet() {
	int n; std::cin >> n;
	std::vector<int> a(n + 1), b(n + 1);
	std::unordered_map<int, std::vector<int>> pos;
	std::vector<int> la(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		pos[b[i]].emplace_back(i);
	}

	for (int i = 1; i <= n; i++) {
		auto &v = pos[a[i]];
		auto it = std::upper_bound(v.begin(), v.end(), i);
		if (it != v.begin()) la[i] = *--it;
		else la[i] = 0;
	}

	Fenwick<int> t(n);

	long long ans = 0;
	std::unordered_map<int, std::vector<int>> cur;
	for (int i = 1; i <= n; i++) {
		int l = la[i] + 1;

		cur[a[i]].emplace_back(i);
		auto pt2 = cur.find(b[i]);
		if (pt2 != cur.end()) {
			for (auto &idx: pt2->second) t.add(idx, 1);
			cur.erase(pt2);
		}
		ans += t.sum(l, i);
	}
	std::cout << ans << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
