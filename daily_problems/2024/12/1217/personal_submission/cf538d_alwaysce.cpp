#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	/*
		o->x全部都能到达
		o->.全部排除
	*/
	vector<string> grid(n);
	for (auto& x: grid) {
		cin >> x;
	}
	
	vector<string> ans(2 * n - 1, string(2 * n - 1, 'x'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'o') {
				for (int ni = 0; ni < n; ni++) {
					for (int nj = 0; nj < n; nj++) {
						if (grid[ni][nj] == '.') {
							// v = (ni - i), (nj - j)
							ans[ni - i + n - 1][nj - j + n - 1] = '.';
						}
					}
				}
			}
		}
	}	
	
	ans[n - 1][n - 1] = 'o';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'x') {
				bool flag = false;
				for (int ni = 0; ni < 2 * n - 1; ni++) {
					for (int nj = 0; nj < 2 * n - 1; nj++) {
						if (ans[ni][nj] == 'x') {
							int di = i - (ni - n + 1);
							int dj = j - (nj - n + 1); // x往回走能遇到o
							//只要其中一个方向能走回o就行
							if (di >= 0 and di < n and dj >= 0 and dj < n and grid[di][dj] == 'o') {
								flag = true;
							}
						}
					}
				}
				if (!flag) {
					cout << "NO";
					return 0;
				}
			}
		}
	}	
	
	cout << "YES\n";
	for (auto& x: ans) {
		cout << x << '\n';
	}
	return 0;
}
