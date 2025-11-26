#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
    cin >> t;
    while (t--) {
        string s;
		cin >> s;

		int n = s.size();
		bool has0 = false;
		for (char c : s) {
			if (c == '0') {
				has0 = true;
				break;
			}

		}

		if (!has0) {
			cout << 0 << "\n";
			continue;
		}

		// nxt[i][j]: s[i:...]中 数字j第一次出现的位置
		vector<vector<int>> nxt(n + 2, vector<int>(10, -1));
		for (int i = n - 1; i >= 0; i--) {
			for (int d = 0; d <= 9; d++) {
				nxt[i][d] = nxt[i + 1][d];
			}
			nxt[i][s[i] - '0'] = i;
		}

		// dp[i]: s[i...]开始匹配 能够构成的最短缺失子序列长度
		vector<int> dp(n + 2);
		int inf = 1e9;
		dp[n] = dp[n + 1] = 1;

		for (int i = n - 1; i >= 0; i--) {
			dp[i] = inf;
			for (int d = 0; d <= 9; d++) {
				int nxt_pos = nxt[i][d];
				if (nxt_pos != -1) {
					dp[i] = min(dp[i], dp[nxt_pos + 1] + 1);
				} else {
					dp[i] = 1;
				}
			}
		}

		int ans_len = inf;
		int first_digit = -1;
		for (int d = 1; d <= 9; d++) {
			int nxt_pos = nxt[0][d];
			int len;
			if (nxt_pos != -1) {
				len = 1 + dp[nxt_pos + 1];
			} else {
				len = 1;
			}
			if (len < ans_len) {
				ans_len = len;
				first_digit = d;
			}
		}

		cout << first_digit;
		int curr_pos = nxt[0][first_digit];
		if (curr_pos == -1) {
			cout << '\n';
			continue;
		}

		for (int k = 1; k < ans_len; k++) {
			int nxt_d = -1;
			for (int j = 0; j < 10; j++) {
				int pos = nxt[curr_pos + 1][j];
				int len;
				if (pos == -1) {
					len = 1;
				} else {
					len = 1 + dp[pos + 1];
				}

				if (len == ans_len - k) {
					nxt_d = j;
					break;
				}
			}
			cout << nxt_d;
			curr_pos = nxt[curr_pos + 1][nxt_d];
		}
		cout << '\n';
    }
	
	return 0;
}
