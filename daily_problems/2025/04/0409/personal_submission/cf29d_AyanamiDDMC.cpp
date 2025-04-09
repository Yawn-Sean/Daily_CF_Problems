#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 310;

vector<int> head[N], ans;

void add(int u, int v) {
	head[u].push_back(v);
}

bool dfs(int u, int fa, int t) {
	if (u == t) return true;

	for (int v : head[u]) {
		if (v != fa && dfs(v, u, t)) {
			ans.push_back(v);
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}

	int t = 1, s;
	while (cin >> s) dfs(s, 0, t), t = s;
	dfs(1, 0, t);

	ans.push_back(1);
	if (ans.size() != 2 * n - 1) {
		cout << -1 << "\n";
		return 0;
	}

	for (int x : ans) cout << x << " ";
	cout << "\n";
	return 0;
}
