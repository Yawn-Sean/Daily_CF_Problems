#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> f(k + 1);
	string d;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		cin >> d;
		vector<int> q;
		for (int j = 0; j < m; j ++) {
			if (d[j] == '1')
				q.emplace_back(j);
		}
		if (q.empty()) {
			continue;
		}

		int tot = q.back() - q.front() + 1, sz = (int)q.size();
		ans += tot;
		vector<int> g(sz + 1);
		g[sz] = tot;
		for (int x = 0; x < sz; x ++){
			for (int y = 0; y <= x; y ++){
				g[sz - (x - y + 1)] = max(g[sz - (x - y + 1)], tot - (q[x] - q[y] + 1));
			}
		}

		for (int x = k; x > 0; x --) {
			for (int y = 1; y <= sz; y ++) {
				if (x < y) continue;
				f[x] = max(f[x], f[x - y] + g[y]);
			}
		}
	}
	cout << ans - f[k] << endl;
	return 0;
}
