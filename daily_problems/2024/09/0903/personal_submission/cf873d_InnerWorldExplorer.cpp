#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (k % 2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 1);
	auto dfs = [&](auto self, int l, int r) -> void{
		if (k == 1) return;
		if (l + 1 == r) return;
		k -= 2;
		int m = (l + r) / 2;
		swap(ans[m - 1], ans[m]);
		self(self, l, m);
		self(self, m, r);
	};
	dfs(dfs, 0, n);
	if (k != 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i ++){
		cout << ans[i] << " \n"[i == n - 1];
	}
	return 0;
}
