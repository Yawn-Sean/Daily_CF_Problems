#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		每次操作(x,y) => x行从x到y y列从x到y进行颜色的翻转
		所以每次的操作都会一个框的操作
		距离对角线越远的更难被操作
		
	*/
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			grid[i][j] = (c - '0');
		}
	}
	
	int ans = 0;
	vector<int> r0(n), c0(n);
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (grid[i][j] != (r0[i] ^ c0[j])) {
				ans++;
				r0[i] ^=1;
				c0[j] ^=1;
			}
		}
	}
	
	vector<int> r1(n), c1(n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (grid[i][j] != (r1[i] ^ c1[j])) {
				ans++;
				r1[i]^=1;
				c1[j]^=1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (grid[i][i] != (r0[i] ^ c0[i] ^ r1[i] ^ c1[i])) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
