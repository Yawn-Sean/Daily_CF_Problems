#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y, y --;

	vector<vector<int>> tag(n, vector<int>(n, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] / n == i) tag[i][j] |= 1;
			if (grid[i][j] % n == j) tag[i][j] |= 2;
			if (!tag[i][j]) return cout << "No", 0;
		}
	}

	vector<vector<int>> block_tag(n, vector<int>(n, 0));

	for (int i = 0; i < n; i ++) {
		int cur = -1;
		vector<int> diff(n, 0);

		for (int j = 0; j < n; j ++) {
			if (tag[i][j] == 1) {
				if (grid[i][j] < cur) return cout << "No", 0;
				cur = grid[i][j];

				int l = grid[i][j] % n, r = j;
				if (l > r) swap(l, r);
				diff[l + 1] ++, diff[r] --;
			}
		}

		for (int j = 1; j < n; j ++) diff[j] += diff[j - 1];

		for (int j = 0; j < n; j ++) {
			if (diff[j] && tag[i][j] == 3) {
				block_tag[i][j] ++;
			}
		}
	}

	for (int j = 0; j < n; j ++) {
		int cur = 0;
		vector<int> diff(n, 0);

		for (int i = 0; i < n; i ++) {
			if (tag[i][j] == 2) {
				if (grid[i][j] < cur) return cout << "No", 0;
				cur = grid[i][j];

				int l = grid[i][j] / n, r = i;
				if (l > r) swap(l, r);
				diff[l + 1] ++, diff[r] --;
			}
		}

		for (int i = 1; i < n; i ++) diff[i] += diff[i - 1];

		for (int i = 0; i < n; i ++) {
			if (diff[i] && tag[i][j] == 3) {
				block_tag[i][j] ++;
			}
		}
	}

	for (auto &x: block_tag) for (auto &y: x) if (y == 2) return cout << "No", 0;

	cout << "Yes";

	return 0;
}