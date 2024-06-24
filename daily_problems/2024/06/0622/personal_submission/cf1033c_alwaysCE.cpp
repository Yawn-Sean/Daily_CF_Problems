#include <bits/stdc++.h>

using i64 = long long;

int inf = 1E9;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	std::vector<std::vector<int>> adj(n, std::vector<int>());
	for (int i = 0; i < n; i++) {
		for (int j = i + a[i]; j < n; j += a[i]) {
			if (a[j] > a[i]) {
				adj[i].push_back(j);			
			}
		}
		for (int j = i - a[i]; j >= 0; j -= a[i]) {
			if (a[j] > a[i]) {
				adj[i].push_back(j);			
			}
		}
	}
	
	std::vector<int> dp(n, -1);
	std::function<int(int)> dfs = [&](int x) -> int {
		if (dp[x] != -1) {
			return dp[x];
		}
		
		int win = 0;
		for (auto& y: adj[x]) {
			// y出发 Bob必输 此时Alice必胜
			if (dfs(y) == 0) {
				win = 1;
				break;
			}
		}
		
		return dp[x] = win;
	};
	
	for (int i = 0; i < n; i++) {
		if (dp[i] == -1) {
			dfs(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		std::cout << (dp[i] == 1 ? 'A': 'B');
	}
	std::cout << '\n';
	return 0;
}
