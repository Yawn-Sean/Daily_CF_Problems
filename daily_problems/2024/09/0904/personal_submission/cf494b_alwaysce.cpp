#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

vector<int> z_function(string& s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		// i落在z-window内 且剩余的长度大于之前的对称位置 直接得出答案
		if (i <= r and z[i - l] < r - i + 1) {
			z[i] = z[i - l];
		} else {
			z[i] = max(0, r - i + 1);
			while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
				z[i]++;
			}
		}
		// 维护z-window [l, r]
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s, t;
	cin >> s >> t;
	
	string cur = t + '#' + s;
	vector<int> sz = z_function(cur);
	
	// s中所有出现t的开始下标
	int n = s.size(), k = t.size();
	vector<int> pos(n, -1);

	// z函数 记录的是s与t匹配的开始位置
	for (int i = 0; i < n; i++) {
		if (sz[k + 1 + i] >= k) {
			// [i, i + k - 1]匹配了t
			// pos[i]记录的是i位置左侧 完整匹配t的(最近一个)右端点
			pos[i + k - 1] = i + k - 1;
		}
	}

	for (int i = 1; i < n; i++) {
		if (pos[i] == -1) {
			pos[i] = pos[i - 1];
		}
	}
	
	// for (auto& v: pos) {
		// cout << v << ' ';
	// }
	// cout << '\n';
	vector<i64> dp(n, 0);
	vector<i64> dp_acc(n, 0);
	vector<i64> dp_pre(n, 0);
	
	for (int i = 0; i < n; i++) {
		if (pos[i] != -1) {
			// 在i位置结束有dp[i]种分割的方式
			// 0 ... | pos[i]-sz1+1 : pos[i] |
			dp[i] = pos[i] - k + 2;
		}
		// 在i位置&之前的总方案数 = dp_pre[i]
		if (pos[i] >= k) {
			// 0 ... pos[i]-sz1, |t|
			dp[i] += dp_pre[pos[i] - k] % mod;
		}
		if (i > 0) {
			dp_acc[i] = dp_acc[i - 1];
			dp_pre[i] = dp_pre[i - 1];
		}
		dp_acc[i] += dp[i] % mod;
		// dp_pre[i]: dp[i]的前缀和
		dp_pre[i] += dp_acc[i] % mod;
	}
	
	cout << (dp_acc[n - 1] + mod) % mod;
	
    return 0;
    
}
