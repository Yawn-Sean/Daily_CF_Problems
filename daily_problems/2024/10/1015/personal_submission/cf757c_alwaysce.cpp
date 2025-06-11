#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	// 进化计划是 {1, 2, ..., m} 的排列 f ，其中 f(x) = y 表示类型为 x 的小精灵进化成类型为 y 的小精灵
	vector<vector<int>> g(m);
	for (int i = 0; i < n; i++) {
		int gi;
		cin >> gi;
		while (gi--) {
			int x;
			cin >> x;
			g[x - 1].push_back(i);
		}
	}
	
	// 只有某个元素x和y出现的次数在i和j内完全一样才能交换
	// i: {x, y}
	// j: {x, y}
	// x: {i, j}
	// y: {i, j} 对于x元素就可以交换
	sort(g.begin(), g.end());
	i64 cur = 1, ans = 1;
	i64 mod = 1e9 + 7;
	
	for (int i = 1; i < m; i++) {
		if (g[i] == g[i - 1]) {
			cur++;
		} else {
			cur = 1;
		}
		// cur!种方案
		ans = 1ll * ans * cur % mod;
	}
	
	cout << ans % mod;
    return 0;
}
