#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> parent(n + 1);
	for (int i = 2; i <= n; i ++) cin >> parent[i];

	vector<int> dis(n + 1), chosen(n + 1);

	for (int i = n; i > 1; i --) {
		if (dis[i] == k - 1) chosen[i] = 1;
		else dis[parent[i]] = max(dis[parent[i]], dis[i] + 1);
	}

	chosen[1] = 1;

	int ans = 0;
	for (auto &x: chosen) ans += x;

	cout << ans << '\n';
	for (int i = 1; i <= n; i ++) if (chosen[i]) cout << i << ' ';

	return 0;
}