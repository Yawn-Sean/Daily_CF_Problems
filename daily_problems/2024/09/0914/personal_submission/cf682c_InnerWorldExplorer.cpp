#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	vector<map<int, int>> g(n + 1);
	int p, c;
	for (int i = 1; i < n; i ++) {
		cin >> p >> c;
		g[p][i + 1] = c;
	}

	int ct = 1;
	auto dfs = [&](auto && self, int root, long long d) -> void {
		for (auto &[k, v] : g[root]) {
			long long tmp = d >= 0 ? d + v : v;
			if (a[k - 1] >= tmp) {
				self(self, k, tmp);
				ct ++;
			}
		}
	};
	dfs(dfs, 1, 0);
	cout << n - ct << endl;
	return 0;
}
