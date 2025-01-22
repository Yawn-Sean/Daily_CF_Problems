#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	提示：考虑n*m矩形内的square数量
	n < m
	mn = min(n, m)
	p = (m-n+1)
	n,m=3,5
	p=3 
	边长为 mn 有 1 * 3 个
	边长为 mn-1 有2* 4 个
	// ...
	// 边长为1有 3 * 5 个
	
	S(n,m) = sum_{k=1}^n(km) - sum_{k=1}^n{k^2} + sum_{k=1}^n{k}
		扣掉一个平方和 再加回去一个求和
		
	只会枚举 n<=m的部分 剩下的是对称的
		m * ((n+1)*n/2) - n*(n+1)*(1/2 - 2n+1/6) = x
		n给定了m可以直接算出来
	
	m * (n(n+1)/2) - (n(n+1)(2n+1) / 6) = x
	*/
	
	i64 x;
	cin >> x;
	
	vector<pair<i64,i64>> ans;
	i64 mx = 2e6;
	for (i64 n = 1; n <= mx; n++) {
		i64 f1 = n * (n + 1) / 2;
		// f1 * m - f2 = x
		// m = (f2 + x) / f1
		i64 f2 = x + n * (n + 1) * (n - 1) / 6;
		if (f2 % f1 == 0 and (n <= f2 / f1)) {
			ans.push_back({n, f2 / f1});
		}
	}
	
	int add = 0;
	if (ans.size()) {
		if (ans.back().first == ans.back().second) {
			add = 1;
		}	
	}
	
	cout << 2ll * ans.size() - add << '\n';
	for (auto& pr: ans) {
		cout << pr.first << ' ' << pr.second << '\n';
	}
	
	reverse(ans.begin(), ans.end());
	for (int i = add; i < ans.size(); i++) {
		cout << ans[i].second << ' ' << ans[i].first << '\n';
	}
	
    return 0;
}
