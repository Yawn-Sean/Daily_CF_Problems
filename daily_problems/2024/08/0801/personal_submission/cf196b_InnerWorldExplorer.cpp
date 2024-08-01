#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using pi = pair<int, int>;

const int INF = 1E9;
const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};

/**
 * Description: wraps a lambda so it can call itself
 * Source: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
 */

namespace std {

template <class Fun> class y_combinator_result {
	Fun fun_;

public:
	template <class T>
	explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

	template <class... Args> decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

}  // namespace std

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	int si, sj;
	for (int i = 0; i < n; i ++) {
		cin >> grid[i];
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == 'S') {
				si = i;
				sj = j;
			}
		}
	}
	vector < vector<pi>> vis(n, vector<pi>(m, {INF, INF}));
	vis[si][sj] = {si, sj};

	auto dfs = y_combinator([&](auto dfs, int x, int y) -> bool {
		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i]; //virtual pos
			int rx = (nx % n + n) % n, ry = (ny % m + m) % m; //fixed grid pos
			if (grid[rx][ry] == '#') continue;
			if (vis[rx][ry].first == INF){ //no vis before
				vis[rx][ry] = {nx, ny};
				if (dfs(nx, ny)){
					return true;
				}
			}else if (vis[rx][ry].first != nx || vis[rx][ry].second != ny){ //visited
				return true;
			}
		}
		return false;
	});
	
	cout << (dfs(si, sj) ? "Yes" : "No") << endl;
	return 0;
}
