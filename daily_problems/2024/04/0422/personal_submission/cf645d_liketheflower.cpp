// https://codeforces.com/contest/645/submission/257801287
#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> edges;
    for (int i = 0; i < m; ++i) {
	int u; int v;
	cin >> u >> v;
	--u; --v;
	edges.emplace_back(u, v);
    }

    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);
    auto success = [&](int limit) -> bool {
	indegree.assign(n, 0);
	graph.assign(n, vector<int>());
	for (int i = 0; i < limit; ++i) {
	    auto[u, v] = edges[i];
	    ++indegree[v];
	    graph[u].push_back(v);
	}

	vector<int> zero_degree_nodes;
	for (int i = 0; i < n; ++i) {
	    if (indegree[i] == 0) {
		zero_degree_nodes.push_back(i);
	    }
	}

	while (!zero_degree_nodes.empty()) {
	    if (zero_degree_nodes.size() > 1) {
		return false;
	    }
	    vector<int> next_zero_degree_nodes;
	    for (auto curr : zero_degree_nodes) {
		for (auto& nei : graph[curr]) {
		    --indegree[nei];
		    if (indegree[nei] == 0) {
			next_zero_degree_nodes.push_back(nei);
		    }
		}
	    }
	    zero_degree_nodes = move(next_zero_degree_nodes);
	}
	return true;
    };

    int lo = 1, hi = m;
    while (lo < hi) {
	auto mid = (lo + hi) / 2;
	if (success(mid)) {
	    hi = mid;
	} else {
	    lo = mid + 1;
	}
    }
    if (success(lo)) {
	cout << lo << '\n';
    } else {
	cout << -1 << '\n';
    }

    return 0;
}
