#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> child(n + 2);
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
    	if (a[i] == -1){
    		a[i] = i + 1;
    	}
    	child[a[i]].push_back(i);
    }
    vector<int> p(n + 2, 0);
    int t = n, ok = 1;

    auto dfs = [&](auto self, int l, int r) -> void {
    	if (l > r) return;
    	if (a[r] != r + 1 || !child[l].empty()){
    		ok = 0;
    		return;
    	}
    	int last = l - 1;
    	for (auto &v : child[r + 1]){
    		if (v < l || (!child[v].empty() && child[v][0] < last)){
    			ok = 0;
    			return;
    		}
    		p[v] = t--;
    		self(self, last + 1, v - 1);
    		last = v;
    	}
    };
    dfs(dfs, 1, n);
    if (!ok){
    	cout << "-1\n";
    	return;
    }

    for (int i = 1; i <= n; i++){
    	cout << p[i] << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}