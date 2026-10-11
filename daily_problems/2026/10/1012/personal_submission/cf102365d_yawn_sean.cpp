#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, J;
	cin >> n >> J;

	vector<int> upward(J + 1, 0), downward(J + 1, 0);

	for (int i = 1; i <= J; i ++) cin >> upward[i];
	for (int i = 1; i <= J; i ++) cin >> downward[i];

	vector<int> dis(2 * n + 1, (int)1e9), vis(2 * n + 1, 0);

	dis[n] = 0, vis[n] = 1;
	int chosen = n;

	for (int x = 0; x < 2 * n; x ++) {
		for (int i = 1; i <= J; i ++) {
			int u;
			u = chosen + i;
			if (u <= 2 * n) dis[u] = min(dis[u], dis[chosen] + upward[i]);
			u = chosen - i;
			if (u >= 0) dis[u] = min(dis[u], dis[chosen] + downward[i]);
		}

		int nchosen = -1;
		for (int u = 0; u <= 2 * n; u ++) {
			if (!vis[u] && (nchosen == -1 || dis[u] < dis[nchosen])) {
				nchosen = u;
			}
		}

		chosen = nchosen;
		vis[chosen] = 1;
	}

	vector<int> dp_l(n + 1, (int)1e9), dp_r(n + 1, (int)1e9);
	dp_l[1] = 0, dp_r[1] = 0;

	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			int v = max(dp_r[j], dp_l[i - j]);
			dp_l[i] = min(dp_l[i], v + dis[n + j]);
			dp_r[i] = min(dp_r[i], v + dis[n - (i - j)]);
		}
	}

	cout << dp_l[n];

	return 0;
}