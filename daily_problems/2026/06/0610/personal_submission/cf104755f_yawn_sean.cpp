#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> holes(n), targets(m);

	for (auto &x: holes) cin >> x;
	for (auto &x: targets) cin >> x;

	sort(holes.begin(), holes.end());
	sort(targets.begin(), targets.end());

	vector<int> ans, vis(m, 0);

	for (auto &v: targets) {
		int pt = 0;
		bool flg = true;

		for (auto &x: holes) {
			while (pt < m && targets[pt] < v + 2 * (x - holes[0])) pt ++;
			if (pt == m || targets[pt] != v + 2 * (x - holes[0])) flg = false;
		}

		if (flg) {
			ans.emplace_back(2 * holes[0] - v);
			pt = 0;

			for (auto &x: holes) {
				while (pt < m && targets[pt] < v + 2 * (x - holes[0])) pt ++;
				vis[pt] = 1;
			}
		}
	}

	if (*min_element(vis.begin(), vis.end())) {
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i ++)
			cout << ans[i] << " \n"[i + 1 == ans.size()];
	}
	else cout << "No\n";

	return 0;
}