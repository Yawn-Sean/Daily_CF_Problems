#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n);
	std::vector<std::vector<i64>> cnt(m);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (i64 i = 0; i < n; i++) {
		cnt[a[i] % m].push_back(i);	
	}
	
	i64 need = (n / m);
	i64 ans = 0;
	std::stack<i64> stk;
	
	for (i64 i = 0; i < 2 * m; i++) {
		i64 cur = (i % m);
		while (!stk.empty() and (i64)cnt[cur].size() < need) {
			i64 j = stk.top();
			stk.pop();
			i64 cost = (cur - (a[j] % m) + m) % m;
			ans += cost;
			a[j] += cost;
			cnt[cur].push_back(j);
		}
		
		while ((i64)cnt[cur].size() > need) {
			i64 j = cnt[cur].back();
			stk.push(j);
			cnt[cur].pop_back();
		}
	}
	
	std::cout << ans << '\n';
	for (auto& x: a) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
