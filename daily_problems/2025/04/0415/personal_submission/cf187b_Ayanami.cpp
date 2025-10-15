#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 70, K = 1010, Q = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m, q_num, max_k;
int g[N][N][N];
struct Query {
	int u, v, k;
} q[Q];
int f[N][N][K];

void floyd() {
	for (int c = 1; c <= m; ++c) {
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					g[c][i][j] = min(g[c][i][j], g[c][i][k] + g[c][k][j]);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> q_num;
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> g[k][i][j];
			}
		}
	}

	for (int i = 0; i < q_num; ++i) {
		cin >> q[i].u >> q[i].v >> q[i].k;
		max_k = max(max_k, q[i].k);
	}
	// 最多换乘n - 1次
	max_k = min(max_k, n - 1);

	floyd();

	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int c = 1; c <= m; ++c) {
				f[i][j][0] = min(f[i][j][0], g[c][i][j]);
			}
		}
	}

	for (int c = 1; c <= max_k; ++c) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j][c] = f[i][j][c - 1];
			}
		}

		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					f[i][j][c] = min(f[i][j][c], f[i][k][c - 1] + f[k][j][0]);
				}
			}
		}
	}

	for (int i = 0; i < q_num; ++i) {
		auto [u, v, k] = q[i];
		k = min(k, max_k);
		cout << f[u][v][k] << "\n";
	}

	return 0;
}
