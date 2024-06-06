#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz, minT;
    DSU(int n) : f(n), siz(n, 1), minT(n, 0) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) std::swap(x, y);
        siz[x] += siz[y];
        f[y] = x;
        minT[x] = min(minT[x], minT[y]);
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<array<int,3>> data(n);
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < 3; j++){
    		cin >> data[i][j];
    	}
    }


    DSU compo(n);
    for (int i = 0; i < n; i++){
    	compo.minT[i] = data[i][2];
    }
    
    map<int, vector<array<int,2>>> rows, cols;
    for (int i = 0; i < n; i++){
    	auto [x, y, t] = data[i];
    	rows[x].push_back({y, i});
    	cols[y].push_back({x, i});
    }
    
    for (auto &[_, v] : rows){
    	sort(v.begin(), v.end());
    	int sz = v.size();
    	for (int i = 1; i < sz; i++){
    		if (v[i][0] - v[i - 1][0] <= k){
    			compo.merge(v[i][1], v[i - 1][1]);
    		}
    	}
    }
    for (auto &[_, v] : cols){
    	sort(v.begin(), v.end());
    	int sz = v.size();
    	for (int i = 1; i < sz; i++){
    		if (v[i][0] - v[i - 1][0] <= k){
    			compo.merge(v[i][1], v[i - 1][1]);
    		}
    	}
    }

    vector<int> a;
  	for (int i = 0; i < n; i++) if (compo.leader(i) == i){
  		a.push_back(compo.minT[i]);
  	}
  	//cout << a.size() <<"-----\n";
  	sort(a.begin(), a.end());
  	int nn = a.size();
  	int res = nn - 1;
  	for (int i = 0; i < nn; i++){
  		res = min(res, max(nn - i - 2, a[i]));
  	}
  	cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}