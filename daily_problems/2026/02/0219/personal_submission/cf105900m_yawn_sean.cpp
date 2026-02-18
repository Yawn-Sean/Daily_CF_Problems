#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

const int N = 1e6 + 3e5 + 5;
int trie[N][26], weights[N];
int rt = 1, pt = 1;

void insert_char(char ch) {
	pt ++;
	trie[pt][ch - 'a'] = rt;
	weights[pt] = weights[rt];
	rt = pt;
}

void insert_string(string s) {
	int cur = rt; weights[rt] ++;

	for (auto &ch: s) {
		if (!trie[cur][ch - 'a'])
			trie[cur][ch - 'a'] = ++pt;
		cur = trie[cur][ch - 'a'];
		weights[cur] ++;
	}
}

void query(string s) {
	long long ans = 0;
	int cur = rt;

	for (auto &ch: s) {
		if (!trie[cur][ch - 'a']) break;
		cur = trie[cur][ch - 'a'];
		ans += weights[cur];
	}

	cout << ans << '\n';
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> path(n);

	while (m --) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
	}

	long long inf = 1e12;
	vector<long long> dis(n, inf);

	dis[0] = 0;

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, 0});

	vector<int> order;

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dis[u] == d) {
			order.emplace_back(u);
			for (auto &[v, w]: path[u]) {
				if (dis[v] > d + w) {
					dis[v] = d + w;
					pq.push({dis[v], v});
				}
			}
		}
	}

	vector<int> ans(n, 1'000'000);
	ans[0] = 0;

	for (auto &u: order) {
		for (auto &[v, w]: path[u]) {
			if (dis[v] == dis[u] + w) {
				ans[v] = min(ans[v], max(ans[u], w));
			}
		}
	}

	cout << dis[n - 1] << ' ' << ans[n - 1];

	return 0;
}