#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = LLONG_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		有m个问题 n个朋友 b元可以买一个显示器
		
		第i个朋友 花费xi解决他知道的所有问题mi个
		但是需要至少已有ki个显示器才会帮忙
		
		花最少的钱 解决所有问题, 最初没有显示器
		
		1 ≤ n ≤ 100 ; 1 ≤ m ≤ 20 ; 1 ≤ b ≤ 109
		
		状态压缩dp
	*/
	int n, m, b;
	cin >> n >> m >> b;
	
	// 第i个朋友需要x[i]元 至少k[i]个显示器 才会解决mask状态问题
	vector<i64> k(n), x(n), mask(n);
	map<i64, vector<int>> kcnt;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> x[i] >> k[i] >> num;
		kcnt[k[i]].push_back(i);
		int sol = 0;
		while (num--) {
			int x;
			cin >> x;
			x--;
			sol |= (1 << x);
		}
		mask[i] = sol;
	}
	
	int mx = (1 << m) - 1;
	vector<i64> dp(mx + 1, inf);
	dp[0] = 0;
	
	i64 ans = inf;
	// 从小到大枚举所需要的显示器数量
	for (auto& pr: kcnt) {
		i64 kneed = pr.first;
		
		for (auto& idx: pr.second) {
			for (int msk = mx; msk >= 0; --msk) {
				if (dp[msk] == inf)
					continue;
				
				int new_msk = msk | mask[idx];
				if (dp[new_msk] > dp[msk] + x[idx]) {
					dp[new_msk] = dp[msk] + x[idx];
				}
			}
			if (dp[mx] != inf) {
				i64 tmp = kneed * b + dp[mx];
				ans = min(ans, tmp);
			}
		}
	}
	
	cout << (ans != inf ? ans : -1);
    return 0;
}
