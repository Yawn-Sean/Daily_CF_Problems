#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, i, j;
	while (cin >> n >> m) {
		vector<int> a(n), b(m);
		vector<vector<int>> mat(n, vector<int> (m, 0));
		int row = 0, col = 0;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			row ^= a[i];
		}
		for (i = 0; i < m; ++i) {
			cin >> b[i];
			col ^= b[i];
		}
		if (col == row) {
			cout << "YES\n";
			int ans = 0;
			for (i = 0; i < n - 1; ++i) {
				ans ^= a[i];
				mat[i][m - 1] = a[i];
			}
			for (i = 0; i < m - 1; ++i) {
				mat[n - 1][i] = b[i];
			}
			ans ^= b[m - 1];
			mat[n - 1][m - 1] = ans;
			for (i = 0; i < n; ++i) {
				for (j = 0; j < m; ++j) {
					cout << mat[i][j] << ' ';
				}
				cout << '\n';
			}

		} else {
			cout << "NO\n";
		}

	}

	return 0;
}

/*
	for (i = 0; i < n - 1; ++i) {
		ans ^= a[i];
		mat[i][m - 1] = a[i];
	}
	ans ^= b[m - 1];
	a1 ^ a2 .... ^ an-1 ^ bm
	a1 ^ a2 .... ^ an-1 ^ a1 ^ a2 .... ^ an-1 ^ bm-1 = bm
	所以mat[i][m-1] = a[i];
	for (i = 0; i < m - 1; ++i) {
		mat[n - 1][i] = b[i];
	}
	mat[n - 1][i] = b[i];
	b1 ^ b2 ^ ... bm ^ a1 ^ a2 .... ^ an-1 = an;
*/