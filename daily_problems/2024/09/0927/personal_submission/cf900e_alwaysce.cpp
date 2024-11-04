#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m;
	cin >> m;
	
	vector<int> check_a(n + 1), check_b(n + 1), cnt_q(n + 1);
	
	for (int i = 0; i < n; i++) {
		cnt_q[i + 1] = cnt_q[i] + (s[i] == '?');
	}
	
	for (int i = n - 1; i >= 0; i--) {
		// i位置以a开头的最长交替序列长度
		check_a[i] = (s[i] != 'b' ? check_b[i + 1] + 1 : 0);
		check_b[i] = (s[i] != 'a' ? check_a[i + 1] + 1 : 0);
	}
	// 前 i个位置匹配 j个目标串的最小修改数量
	vector<int> dp(n + 1), change(n + 1); // 最小修改次数
	for (int i = 0; i < n; i++) {
		if (dp[i] > dp[i + 1] or (dp[i] == dp[i + 1] and change[i] < change[i + 1])) {
			dp[i + 1] = dp[i];
			change[i + 1] = change[i];
		}
		
		if (check_a[i] >= m) {
			int nv = dp[i] + 1, nc = change[i] + cnt_q[i + m] - cnt_q[i];
			if (nv > dp[i + m] or (nv == dp[i + m] and nc < change[i + m])) {
				dp[i + m] = nv;
				change[i + m] = nc;
			}
		}
	}
	
	cout << change[n];
	return 0;
}
