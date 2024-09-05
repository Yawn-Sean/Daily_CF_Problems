#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve(){
	int n, k;
	std::cin >> n >> k;

	std::vector<std::string> g(n);
	for (int i = 0; i < n; ++ i) std::cin >> g[i];
	std::vector<std::vector<int>> f(n, std::vector<int>(n, 2 * n));
	f[0][0] = 0;

	int mi = -1, mj = -1;

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			f[i][j] = g[i][j] == 'a' ? 0 : 1;
			if (i || j)
				f[i][j] += std::min(i ? f[i - 1][j] : inf32, j ? f[i][j - 1] : inf32);
			if (f[i][j] <= k && i + j > mi + mj)
				mi = i, mj = j;
		}
	}

	if (f[n - 1][n - 1] <= k) {
		std::cout << std::string(2 * n - 1, 'a');
		return;
	}
	std::vector<std::pair<int, int>> q;

	if (mi != -1){
		std::cout << std::string(mi + mj + 1, 'a');
		for (int i = 0; i < n; ++ i) 
			for (int j = 0; j < n; ++ j) 
				if (f[i][j] == f[mi][mj] && mi + mj == i + j)
					q.emplace_back(i, j);
	}
	else
		q.emplace_back(0, 0), std::cout << g[0][0];

	int dir[3]{0, 1, 0};

	std::vector<std::pair<int, int>> nq;
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));

	while (q.size()) {
		char mic = 'z';
		nq.clear();
		for (auto &[x, y] : q) {
			if (x == n - 1 && y == n - 1) return;
			if (vis[x][y]) continue;
			vis[x][y] = true;
			for (int i = 0; i < 2; ++ i) {
				int nx = x + dir[i], ny = y + dir[i + 1];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (g[nx][ny] == mic) nq.emplace_back(nx, ny);
				else if(g[nx][ny] < mic) mic = g[nx][ny], nq.clear(), nq.emplace_back(nx, ny);
			}
		}
		q.swap(nq);
		std::cout << mic;	
	}

}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}