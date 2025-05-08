#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
struct node {
	int v, c;
};
int n, a[N], fa[N], cnt[N], d[N], ans[N];
vector<node> mp[N];
// 每个城市的优先队列存 (优先级, 城市编号)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q[i].push(make_pair(a[i], i));  // 初始化每个城市的兵种
	}

	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		mp[u].push_back({v, c});
		mp[v].push_back({u, c});
	}

	// BFS 建立树结构
	int l = 1, r = 1;
	d[1] = 1;
	fa[1] = -1;
	cnt[1] = n; // 首都容量视为无限

	while (l <= n) {
		int u = d[l++];
		for (int i = 0; i < mp[u].size(); i++) {
			int v = mp[u][i].v, c = mp[u][i].c;
			if (v == fa[u]) continue;
			fa[v] = u;
			cnt[v] = c;
			d[++r] = v;
		}
	}

	int res = 0, t = 0;
	while (res < n) {
		for (int ii = 1; ii <= n; ii++) {
			int i = d[ii];
			int c = min((int)q[i].size(), cnt[i]);
			while (c--) {
				pair<int, int> tmp = q[i].top(); q[i].pop();
				int pri = tmp.first, id = tmp.second;
				if (i == 1) {
					ans[id] = t; // 记录兵种 id 到达时间
					res++;
				} else {
					q[fa[i]].push(make_pair(pri, id)); // 向父节点移动
				}
			}
		}
		t++;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}
