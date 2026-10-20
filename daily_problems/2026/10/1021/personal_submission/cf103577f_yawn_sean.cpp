#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> cur(n * n + q, 0), cnt_row(n, 0), cnt_col(n, 0);

	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j ++) {
			cur[i * n + q + j] = s[j] - '0';
			cnt_row[i] += s[j] - '0';
			cnt_col[(q + j) % n] += s[j] - '0';
		}
	}

	int start_pos = q;

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int row, col, target;
			cin >> row >> col >> target;
			row --, col --;

			int pos = start_pos + row * n + col;

			cnt_row[row] -= cur[pos];
			cnt_col[pos % n] -= cur[pos];

			cur[pos] = target;

			cnt_row[row] += cur[pos];
			cnt_col[pos % n] += cur[pos];
		}
		else {
			for (int i = 0; i < n; i ++) {
				cnt_row[i] -= cur[start_pos + i * n + (n - 1)];
			}

			for (int i = 0; i < n - 1; i ++) {
				cnt_row[i + 1] += cur[start_pos + i * n + (n - 1)];
			}

			start_pos --;
			cnt_col[start_pos % n] -= cur[start_pos + n * n];

			int target;
			cin >> target;

			cur[start_pos] = target;
			cnt_row[0] += target;
			cnt_col[start_pos % n] += target;
		}

		int ans = 0;

		for (auto &x: cnt_row) ans += (x == n);
		for (auto &x: cnt_col) ans += (x == n);

		cout << ans << '\n';
	}

	return 0;
}