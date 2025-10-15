#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

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
	int n, k;
	i64 l;
	cin >> n >> l >> k;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (k == 1) {
		cout << l % mod;
		return 0;
	}
	
	vector<int> st_range(n);
	iota(st_range.begin(), st_range.end(), 0);
	// 按照循环节内部的大小排序indexes
	sort(st_range.begin(), st_range.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
		
	i64 ans = 0;
	
	// dp[i][j]: 第i节选取第j个a位置元素的子序列数量有多少?
	// dp[1][*] = 1
	// dp[i][j] += dp[i - 1][j'] 满足 a[j'] <= a[j] 成立(不增)
	vector<i64> dp(n * k, 0);
	
	for (int i = 0; i < k; i++) {
		// cur 循环节内前缀和
		int pt = 0;
		i64 cur = 0;
		// 循环节内的大小
		for (auto& j: st_range) {
			int idx = i * n + j; // 初始偏移量
			if (idx >= l) { continue; }
			if (i == 0) {
				dp[idx] = 1ll;
			} else {
				while (pt < n && a[st_range[pt]] <= a[j]) {
                    cur += dp[(i - 1) * n + st_range[pt]];
                    if (cur >= mod) cur -= mod;
                    pt++;
                }
                dp[idx] = cur;
			}
			
			// 可以重复平移几次?
			i64 times = ((l - idx - 1) / n) + 1;
			// cout << idx << ' ' << times << '\n';
            if (times > 0) {
                ans += times % mod * dp[idx] % mod;
                if (ans >= mod) ans -= mod;
            }
		}
	}
	cout << ans;
    return 0;
}
