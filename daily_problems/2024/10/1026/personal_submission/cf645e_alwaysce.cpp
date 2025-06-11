#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		m+n个格子
		前m个已经有了字母 s1, s2, ..., sm
		后面n个可以从前k个字母中挑选
		问组成的不同子序列个数有多少个? (空序列也算)
		dp[i][j]: 长度为i 末尾=j的序列方案个数
		dp[i + 1][x] += sum(dp[i][j] for j = 1,...,k) - dp[i][x] + 1
	*/
	
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	

	int m = s.size();
    vector<int> last(k, -1);    
    for (int i = 0; i < m; i++) {
    	last[s[i] - 'a'] = i;
    }
    
    vector<int> order(k);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
    	return last[i] < last[j];
    });
    
    i64 tot = 0;
    vector<i64> dp(k, 0);
    for (int i = 0; i < m; i++) {
    	int c = (s[i] - 'a');
    	i64 v = tot - dp[c] + 1ll;
    	v = (v + mod) % mod;
    	dp[c] = (dp[c] + v) % mod;
    	tot = (tot + v) % mod;
    }
    
    // 选取上一次出现最靠前的字符 dp值可以取到最大
    for (int i = 0; i < n; i++) {
    	// 靠前的顺序固定
    	int c = order[i % k];
    	
    	i64 v = tot - dp[c] + 1ll;
    	v = (v + mod) % mod;
    	dp[c] = (dp[c] + v) % mod;
    	tot = (tot + v) % mod;
    }
    tot = (tot + 1) % mod;
    cout << (tot + mod) % mod;
    return 0;
}
