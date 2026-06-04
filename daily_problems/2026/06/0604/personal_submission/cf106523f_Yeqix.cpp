#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int md = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> L(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
	}

	vector<i64> pw2(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		pw2[i] = pw2[i - 1] * 2 % md;
	}

	i64 ans = 0;
	auto get = [&](i64 x)->i64{
		auto A = L;
		for (int i = 1; i <= n; i++) {
			A[i] += x;
		}

		i64 cnt = 0;
		vector<int> vis(n + 1);
		auto dfs = [&](auto && dfs, int u)->void{
			if (u > n) {
				return;
			}
			if (vis[u]) {
				cnt++;
				return;
			}
			vis[u] = 1;
			dfs(dfs, A[u]);
		};

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(dfs, i);
			}
		}

		return pw2[cnt] - 1;
	};

	for (int i = 0; i <= n; i++) {
		ans = (ans + get(i)) % md;
	}

	cout << ans;
	return 0;
}