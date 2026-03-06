#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	int cnt = 0;
	vector<vector<int>> path(n + 1);
	vector<int> indeg(n + 1, 0);

	vector<int> stk;

	for (auto &x: v1) {
		while (!stk.empty() && stk.back() < x) stk.pop_back();
		if (!stk.empty()) {
			path[stk.back()].emplace_back(x);
			indeg[x] ++;
			cnt ++;
		}
		stk.emplace_back(x);
	}

	stk.clear();

	for (auto &x: v2) {
		while (!stk.empty() && stk.back() > x) stk.pop_back();
		if (!stk.empty()) {
			path[stk.back()].emplace_back(x);
			indeg[x] ++;
			cnt ++;
		}
		stk.emplace_back(x);
	}

	priority_queue<int> pq;
	vector<int> saved_indeg;

	vector<int> w1;

	saved_indeg = indeg;
	for (int i = 1; i <= n; i ++) {
		if (!indeg[i]) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int u = -pq.top(); pq.pop();
		w1.emplace_back(u);

		for (auto &v: path[u]) {
			saved_indeg[v] --;
			if (!saved_indeg[v]) pq.push(-v);
		}
	}

	vector<int> w2;

	saved_indeg = indeg;
	for (int i = 1; i <= n; i ++) {
		if (!indeg[i]) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		w2.emplace_back(u);

		for (auto &v: path[u]) {
			saved_indeg[v] --;
			if (!saved_indeg[v]) pq.push(v);
		}
	}

	bool flg = true;

	for (int i = 0; i < n; i ++) {
		if (i >= w1.size() || i >= w2.size() || v1[i] != w1[i] || v2[i] != w2[i]) {
			flg = false;
		}
	}

	if (!flg) cout << "No\n";
	else {
		cout << "Yes\n";
		cout << cnt << '\n';
		for (int i = 1; i <= n; i ++) {
			for (auto &j: path[i]) {
				cout << i << ' ' << j << '\n';
			}
		}
	}

	return 0;
}