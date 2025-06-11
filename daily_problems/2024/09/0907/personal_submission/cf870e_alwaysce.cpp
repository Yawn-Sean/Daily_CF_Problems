#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<int> xs(n), ys(n);
    map<int,int> mp_x, mp_y;
    
    for (int i = 0; i < n; i++) {
    	cin >> xs[i] >> ys[i];
    	mp_x[xs[i]]++;
    	mp_y[ys[i]]++;
    }
    
    int rank = 0;
    for (auto& pr: mp_x) {
    	mp_x[pr.first] = rank++;
    }
    
    for (auto& pr: mp_y) {
    	mp_y[pr.first] = rank++;
    }
    
    vector<int> edge_cnt(rank, 0);
    DSU d(rank);
    
    for (int i = 0; i < n; i++) {
    	d.merge(mp_x[xs[i]], mp_y[ys[i]]);
    }
    
    for (int i = 0; i < n; i++) {
    	edge_cnt[d.find(mp_x[xs[i]])]++;
    }
    
    i64 ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < rank; i++) {
    	if (edge_cnt[i]) {
    		i64 c = d.size(i);
    		ans = (edge_cnt[i] >= c ? pow(2, c, mod) : pow(2, c, mod) - 1) * ans % mod;
    	}
    }
    cout << ans << '\n';
    return 0;   
}
