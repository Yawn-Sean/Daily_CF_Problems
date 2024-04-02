#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

template<typename T>
struct Fenwick{  //1-indexed
	int n;
	std::vector<T> a;
	Fenwick(T n): n(n), a(n){}

	void add(int x, T v){
		for (int i = x; i < n; i += i & -i){
			a[i] += v;
		}
	}

	T query(int x){
		T res = 0;
		for (int i = x; i; i -= i & -i){
			res += a[i];
		}
		return res;
	}
};

void solve() {
	int n; cin >> n;
	vector<i64> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	vector<vector<array<int,2>>> adj(n);

	for (int i = 1; i < n; i++){
		int p; cin >> p;
		p--;
		int w; cin >> w;
		adj[p].push_back({i, w});
	}

	vector<int> res(n, 0);
	vector<i64> acc{0};
	Fenwick<int> fen(n + 5);

	auto dfs = [&](auto self, int i, int height) -> void {
		auto idx = lower_bound(acc.begin(), acc.end(), acc[height - 1] - a[i]) - acc.begin();
		if (idx < height - 1){
			fen.add(idx + 1, 1);
			fen.add(height, -1);
		}

		for (auto [child, w] : adj[i]){
			acc.push_back(acc.back() + w);
			self(self, child, height + 1);
			acc.pop_back();
		}
		res[i] = fen.query(height);
		fen.add(height, -res[i]);
		fen.add(height + 1, res[i]);
	};
	dfs(dfs, 0, 1);

	for (int i = 0; i < n; i++){
		cout << res[i] << " \n"[i == n - 1];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}