#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<i64> a(m), b(m), c(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	vector<int> order(m);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j) {
		return c[i] < c[j];
	});
	
	/*		
		dp[i天][选择了第j个问题][超过下界a的数值=k] 所能够取到的练习数量最大值
		按照ci排序
		dp[i][j][k] <- dp[i-1][jj < j][kk=0..100] + (if_valid(val={+k, *k}))
			day[i]=j # 第i天选择的是第j个问题
		 	mx[i]=val
		
		if i==n可以取到:
			YES
	*/
	vector<vector<vector<i64> > > dp(n + 2, vector<vector<i64>>(m + 2, vector<i64>(102, -1) ));
	vector<vector<vector<pair<i64,i64> > > > from(n + 2, vector<vector<pair<i64,i64> > >(m + 2, vector<pair<i64,i64>>(102) ));
	dp[0][0][0] = 0;
	for (int j = 1; j <= m; j++) {
		for (int kk = 0; kk <= 100; kk++) {
			if (a[order[j-1]] + kk > b[order[j-1]]) { break; }			
			dp[1][j][kk] = a[order[j-1]] + kk;					
		}
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int jj = 1; jj < j; jj++) {
				if (c[order[jj - 1]] >= c[order[j - 1]]) {
					break;
				}
				
				for (int kk = 0; kk <= 100; kk++) {
					if (dp[i-1][jj][kk] == -1) continue;
					
					i64 actual = a[order[jj-1]] + kk;
					i64 val1 = actual + k;
					i64 val2 = actual * k;
					if (a[order[j-1]] <= val1 and val1 <= b[order[j-1]]) {
						i64 cur_ans = dp[i-1][jj][kk] + val1;
						i64 new_kk = val1 - a[order[j-1]];
						
						if (cur_ans > dp[i][j][new_kk]) {
							dp[i][j][new_kk] = cur_ans;
							from[i][j][new_kk] = {jj, kk};
						}
					}
					
					if (a[order[j-1]] <= val2 and val2 <= b[order[j-1]]) {
						i64 cur_ans = dp[i-1][jj][kk] + val2;
						i64 new_kk = val2 - a[order[j-1]];
						
						if (cur_ans > dp[i][j][new_kk]) {
							dp[i][j][new_kk] = cur_ans;
							from[i][j][new_kk] = {jj, kk};
						}
					}
					
				}
				
			}
		}
		
	}
	
	i64 ans = 0;
	i64 last_j = -1, last_k = -1;
	
	for (int j = 1; j <= m; j++) {
		for (int kk = 0; kk <= 100; kk++) {
			if (dp[n][j][kk] == -1) continue;
			// cout << j << ' ' << kk << ' ' << dp[n][j][kk] << '\n';
			if (dp[n][j][kk] > ans) {
				ans = dp[n][j][kk];
				last_j = j;
				last_k = kk;
			}
		}
	}
	
	if (ans == 0) {
		cout << "NO\n";
		return 0;
	}
	
	vector<pair<i64,i64>> res;
	int x = n;
	while (true) {
		// 第x天 选了j问题 大于a[j] last_k的额度
		// 上一天的问题是
		if (last_j == 0) { 
			break;
		}
		res.push_back({order[last_j - 1] + 1, a[order[last_j-1]] + last_k});		
		
		auto pr = from[x--][last_j][last_k];
		last_j = pr.first;
		last_k = pr.second;
	}
	reverse(res.begin(), res.end());
	cout << "YES\n";
	for (auto& pr: res) {
		cout << pr.first << ' ' << pr.second << '\n';
	}
	return 0;
}

