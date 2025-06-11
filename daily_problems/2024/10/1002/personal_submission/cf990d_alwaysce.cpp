#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<int>> grid(n, vector<int>(n));
	
	if (a > 1) {
		if (b > 1) {
			cout << "NO\n";
			return 0;
		} else {
			for (int i = 0; i <= n - a; i++) {
				for (int j = 0; j <= n - a; j++) {
					if (i != j) {
						grid[i][j] = 1;
					}
				}
			}
		}
	} else {
		if (b > 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j) {
						grid[i][j] = 1;
					}
				}
			}
			for (int i = 0; i <= n - b; i++) {
				for (int j = 0; j <= n - b; j++) {
					if (i != j) {
						grid[i][j] = 0;
					}
				}
			}
		} else {
			if (n == 2 or n == 3) {
				cout << "NO\n";
				return 0;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (abs(i - j) == 1) {
						grid[i][j] = 1;
					}
				}
			}
		}
	}
	
	cout << "YES\n";
	for (auto& x: grid) {
		for (auto& v: x) {
			cout << v;
		}
		cout << '\n';
	}
	
	return 0;
}
