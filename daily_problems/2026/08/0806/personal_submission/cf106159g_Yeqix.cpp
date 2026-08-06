#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

struct DSU {
	vector<int> fa, p, e, f;

	DSU(int n) {
		fa.resize(n + 1);
		iota(fa.begin(), fa.end(), 0);
		p.resize(n + 1, 1);
		e.resize(n + 1);
		f.resize(n + 1);
	}

	int get(int x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}

	bool merge(int x, int y) {
		if (x == y)
			f[get(x)] = 1;
		x = get(x), y = get(y);
		e[x]++;
		if (x == y)
			return false;
		if (x < y)
			swap(x, y);
		fa[y] = x;
		f[x] |= f[y], p[x] += p[y], e[x] += e[y];
		return true;
	}

	bool same(int x, int y) { return get(x) == get(y); }

	bool F(int x) {
		return f[get(x)];
	}

	int size(int x) {
		return p[get(x)];
	}

	int E(int x) {
		return e[get(x)];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<array<i64, 2>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		edge[x].push_back(i), edge[i].push_back(x);
	}

	DSU du(n + 1);
	sort(a.begin() + 1, a.end(), greater<array<i64, 2>>());

	i64 ans = 0, res = 0;
	vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		auto [val, id] = a[i];
		vis[id] = 1, res++;
		for (const auto& v : edge[id]) {
			if (!vis[v]) {
				continue;
			}

			if (!du.same(id, v)) {
				res -= (du.size(id) + 1) / 2 + (du.size(v) + 1) / 2;
				du.merge(id, v);
				res += (du.size(id) + 1) / 2;
			} else {
				res -= du.size(id) % 2;
			}
		}
		ans = max(ans, res * val);
	}

	cout << ans;
	return 0;
}