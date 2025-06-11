#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x, y;
	cin >> n >> x >> y;
	
	vector<int> ls(n), rs(n);
	i64 ans = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> ls[i] >> rs[i];
		rs[i]++;
		ans += 1ll * (rs[i] - ls[i]) * y % mod;
		if (ans >= mod) {
			ans -= mod;
		}
	}
	
	vector<int> st_range(n);
	iota(st_range.begin(), st_range.end(), 0);
	sort(st_range.begin(), st_range.end(), [&](int i, int j) {
		return ls[i] < ls[j];
	});
	
	priority_queue<int, vector<int>, greater<int>> pq_using;
	priority_queue<int> pq_used;

	for (auto &i: st_range) {
		while (!pq_using.empty() and pq_using.top() <= ls[i]) {
			int v = pq_using.top();
			pq_using.pop();
			pq_used.push(v);
		}
		// 组一个新的 x - y
		// 继续用前面旧的 就等于说继续在[v-1: ls]上面用 (ls - v) * y
		// x - y >= (old)则继续用旧的 否则只能用新的
		if (!pq_used.empty() and (x - y) / y >= ls[i] - pq_used.top()) {
			int v = pq_used.top();
			pq_used.pop();
			ans += (ls[i] - v) * y;
		} else {
			// rs++
			ans += x - y;
		}
		
		if (ans >= mod) {
			ans -= mod;
		}
		pq_using.push(rs[i]);
	}
	cout << ans << '\n';

    return 0;
}
