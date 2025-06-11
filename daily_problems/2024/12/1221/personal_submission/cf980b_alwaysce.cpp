#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*

	*/
	int n, k;
	cin >> n >> k;
	
	cout << "YES\n";
	vector<vector<char>> mat(4, vector<char>(n, '.'));
	
	int l = 1, r = n - 2;
	while (k >= 2 and l < r) {
		mat[1][l++] = '#';
		mat[1][r--] = '#';
		k -= 2;
	}
	if (k & 1) {
		mat[1][n/2] = '#';
		--k;
	}
	
	l = 1; r = n - 2;
	while (k >= 2 and l < r) {
		mat[2][l++] = '#';
		mat[2][r--] = '#';
		k -= 2;
	}
	if (k & 1) {
		mat[2][n/2] = '#';
		--k;
	}
	if (k == 2) {
		mat[1][n/2] = '#'; mat[2][n/2] = '#';
	}

	for (auto& row: mat) {
		for (auto& ch: row) {
			cout << ch;
		}
		cout << '\n';
	}
	return 0;
}
