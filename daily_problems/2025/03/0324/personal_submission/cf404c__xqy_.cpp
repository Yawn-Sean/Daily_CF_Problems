#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {
	int n,k;
	cin >> n >> k;
	vector<int> d(n);

	bool ok = true;
	int zero_cnt = 0;
	for (int i = 0 ; i < n ; ++i) {
		cin >> d[i];
		if (!d[i]) ++zero_cnt;
		if (d[i] > n - 1) ok = false;
	}
	if (zero_cnt != 1 || ok == false) {
		cout << "-1\n";
		return;
	}

	vector<vector<int>> g(n);
	for (int i = 0 ; i < n ; ++i) {
		g[d[i]].push_back(i);
	}

	vector<int> deg(n);
	using par = pair<int,int>;
	priority_queue<par , vector<par> , greater<par>> Q;
	Q.push(make_pair(deg[g[0][0]] , g[0][0]));

	vector<pair<int,int>> edge;
	for (int i = 1 ; i < n ; ++i) {
		priority_queue<par , vector<par> , greater<par>> tmp;
		for (auto v : g[i]) {
			if (Q.empty()) {
				cout << "-1\n";
				return;
			}
			auto [_ , u] = Q.top();
			Q.pop();
			if (_ == k) {
				cout << "-1\n";
				return;
			}
			deg[u] += 1;
			deg[v] = 1;
			Q.push(make_pair(deg[u] , u));
			tmp.push(make_pair(deg[v] , v));
			edge.push_back(make_pair(u , v));
		}
		swap(Q , tmp);
	}

	cout << (int)edge.size() << "\n";
	for (auto [u , v] : edge) {
		cout << u + 1 << " " << v + 1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}
