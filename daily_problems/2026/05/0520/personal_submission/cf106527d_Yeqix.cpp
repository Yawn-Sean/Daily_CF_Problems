#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	vector<int> in(n + 1);
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		in[v]++;
	}

	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			que.push(i);
		}
	}

	vector<int> dis(n + 1);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (const auto& v : edge[u]) {
			dis[v] = max(dis[v], dis[u] + 1);
			if (--in[v] == 0) {
				que.push(v);
			}
		}
	}

	if (*max_element(in.begin() + 1, in.end())) {
		cout << "NO\n";
		return 0;
	}

	if (*max_element(dis.begin(), dis.end()) >= 67) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i = 1; i <= m; i++) {
			cout << s[0] << "\n";
		}
	}
	return 0;
}