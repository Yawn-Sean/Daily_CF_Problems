#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		b[i1], b[i2]
		
		- 长度=k
		- i1, i2位于相邻的循环节
		- b[i1] <= b[i2] 成立
		按照循环节内的大小排序
	*/
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		vector<vector<int>> to_fin(n);
		vector<int> ts(m), ps(m);
		for (int i = 0; i < m; i++) {
			int e;
			cin >> e >> ts[i] >> ps[i];
			to_fin[e - 1].push_back(i);
		}
		
		vector<int> ans;
		bool find = true;
		
		int cur = 0;
		for (int i = 0; i < n; i++) {
			int sz = to_fin[i].size();
			
			vector<int> dp(101, inf);
			vector<vector<int>> pres(101, vector<int>(sz + 1, -1));
			dp[0] = 0;
			
			for (int idx = 0; idx < sz; idx++) {
				int option = to_fin[i][idx];
				for (int j = 100; j >= 0; j--) {
					if (dp[j] < inf) {
						int nj = min(j + ps[option], 100);
						if (dp[nj] > dp[j] + ts[option]) {
							dp[nj] = dp[j] + ts[option];
							pres[nj][idx + 1] = option * 101 + j; // [0:idx+1]用哪一个option记录
						}
					}
				}
			}
			
			if (dp[100] > a[i] - cur) {
				find = false;
				break;
			}
			
			cur += dp[100];
			
			int tot = 100;
			for (int j = sz; j > 0; j--) {
				if (pres[tot][j] != -1) {
					ans.push_back(pres[tot][j] / 101); // 选择的option编号
					tot = pres[tot][j] % 101; // 上一个转移的进度来源 
				}
			}
		}
		
		if (find) {
			cout << ans.size() << '\n';
			for (auto& x: ans) {
				cout << x + 1 << ' ';
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	
    return 0;
}
