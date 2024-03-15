#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x; i < n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve(){
    int n; cin >> n;
    vector<i64> val(n);
    vector<vector<int>> adj(n);
    vector<vector<array<i64,2>>> ops(n);

    for (int i = 0; i < n - 1; i++){
    	int u, v; cin >> u >> v;
    	u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int m; cin >> m;
    while(m--){
    	int v; cin >> v;
    	v--;
    	i64 d, x; cin >> d >> x;
    	ops[v].push_back({d, x});
    }


    Fenwick<i64> fen(n + 5);

    auto dfs = [&](auto self, int v, int p, int dep) -> void {
    	for (auto [d, x] : ops[v]){	
    		d += dep;
    		if (d > n) d = n;
    		fen.add(d, x);
    	}
    	val[v] = fen.rangeSum(dep, n + 1);
    	for (auto &u : adj[v]) if (u != p){
    		self(self, u, v, dep + 1);
    	}
    	for (auto [d, x] : ops[v]){
    		d += dep;
    		if (d > n) d = n;
    		fen.add(d, -x);
    	}
    };
    dfs(dfs, 0, -1, 1);
    for (int i = 0; i < n; i++){
    	cout << val[i] << " \n"[i == n - 1];
    }
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
