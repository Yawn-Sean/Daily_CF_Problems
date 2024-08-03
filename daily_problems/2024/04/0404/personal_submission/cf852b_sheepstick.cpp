//code: https://codeforces.com/problemset/submission/852/254913374
//Matrix template stolen from https://cp-algorithms.github.io/cp-algorithms-aux/
void solve() {
	int n, l, m; cin >> n >> l >> m;
	vector<vector<int>> cost(3, vector<int>(n, 0));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < n; j++){
			int y; cin >> y;
			y %= m;
			cost[i][j] = y;
		}
	}
	matrix<mod> a(m, m), b(m, m);
	for (int i = 0; i < n; i++){
		a[0][cost[0][i]] += 1; 
		b[0][cost[1][i]] += 1;
	}

	for (int i = 1; i < m; i++){
		for (int j = 0; j < m; j++){
			a[i][(i + j) % m] = a[0][j];
			b[i][(i + j) % m] = b[0][j];
		}
	}

	auto c = b.pow(l - 2) * a;
	modular<mod> res;
	for (int i = 0; i < n; i++){
		int cnt = (cost[2][i] + cost[1][i]) % m;
		res += c[0][(m - cnt) % m];
	}
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}