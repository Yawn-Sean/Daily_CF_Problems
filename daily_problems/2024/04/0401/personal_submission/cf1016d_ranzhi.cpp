#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> row(n), col(m);
	vector<vector<int>> matrix(n, vector<int>(m));
	int cur = 0;
	for (int i = 0; i < n; i++) cin >> row[i], cur ^= row[i];
	for (int i = 0; i < m; i++) cin >> col[i], cur ^= col[i];
	if (cur != 0) {
		cout << "NO" << endl;
		return;
	}
    cout << "YES" << endl;
	matrix[0][0] = row[0];
	for (int j = 1; j < m; j++) matrix[0][j] = col[j];
	for (int i = 1; i < n; i++) matrix[i][0] = row[i];
	for (int j = 1; j < m; j++) matrix[0][0] ^= matrix[0][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << matrix[i][j] << " ";
		cout << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
