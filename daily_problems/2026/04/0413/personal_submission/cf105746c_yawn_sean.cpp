#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<array<int, 3>>> path(n);
	vector<int> indeg(n, 0);

	while (m --) {
		int u, v, t, r;
		cin >> u >> v >> t >> r;
		u --, v --;
		path[u].push_back({v, t, r});
		indeg[v] ++;
	}

	long long inf = 1e16;
	vector<vector<long long>> best_result(n, vector<long long>(2 * n, inf));

	best_result[0][n] = 0;

	vector<int> stk;
	for (int i = 0; i < n; i ++) {
		if (indeg[i] == 0) {
			stk.emplace_back(i);
		}
	}

	while (!stk.empty()) {
		auto u = stk.back(); stk.pop_back();
		for (auto &[v, t, r]: path[u]) {
			for (int i = 0; i < 2 * n; i ++) {
				if (best_result[u][i] < inf) {
					best_result[v][i + r] = min(best_result[v][i + r], best_result[u][i] + t);
				}
			}
			indeg[v] --;
			if (!indeg[v]) stk.emplace_back(v);
		}
	}

	vector<vector<pair<int, long long>>> total_lines;

	for (int i = 0; i < n; i ++) {
		vector<pair<int, long long>> lines;
		for (int j = 2 * n - 1; j >= 0; j --) {
			int k = j - n;
			long long b = best_result[i][j];
			if (b < inf) {
				while (lines.size() >= 2) {
					auto &[k1, b1] = *(lines.end() - 2);
					auto &[k2, b2] = *(lines.end() - 1);
					if ((k1 - k) * (b2 - b) >= (k2 - k) * (b1 - b)) lines.pop_back();
					else break;
				}
				lines.emplace_back(k, b);
			}
		}
		total_lines.emplace_back(lines);
	}

	auto solve = [&] (int x, int timestamp) -> long long {
		int left = 0, right = total_lines[x].size() - 1;

		while (left < right) {
			int mid = (left + right) / 2;
			auto [k1, b1] = total_lines[x][mid];
			auto [k2, b2] = total_lines[x][mid + 1];
			if (1ll * k1 * timestamp + b1 <= 1ll * k2 * timestamp + b2) right = mid;
			else left = mid + 1;
		}

		auto [k, b] = total_lines[x][left];
		return 1ll * k * timestamp + b;
	};

	while (q --) {
		int l, r, x;
		cin >> l >> r >> x;
		x --;

		if (total_lines[x].empty()) cout << "sorry\n";
		else cout << min(solve(x, l), solve(x, r)) << '\n';
	}

	return 0;
}