#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> cols(n), rows(m);
    for (int i = 0; i < n; i++){
    	cin >> cols[i];
    }
    for (int i = 0; i < m; i++){
    	cin >> rows[i];
    }

    vector<array<int,2>> cc, rr;
    for (int i = 0; i < k; i++){
    	int x, y; cin >> x >> y;
    	auto it = prev(upper_bound(cols.begin(), cols.end(), x));
    	auto itt = prev(upper_bound(rows.begin(), rows.end(), y));


    	if (*it == x && *itt == y) continue;
    	if (*it == x){
    		y = itt - rows.begin();
    		cc.push_back({x, y});
    	}
    	else {
    		x = it - cols.begin();
    		rr.push_back({y, x});
    	}
    }
    i64 res = 0;
    auto gao = [&](vector<array<int,2>> &p, int sz) -> void {
    	sort(p.begin(), p.end());

    	vector<int> cnt(sz, 0);
    	for (int i = 0; i < (int) p.size(); ){
    		int j = i;
    		while(j < (int) p.size() && p[i][0] == p[j][0]){
    			res += cnt[p[j][1]];
    			j++;
    		}
    		for (int k = i; k < j; k++){
    			cnt[p[k][1]]++;
    		}
    		i = j;
    	}
    };
    gao(cc, m);
    gao(rr, n);
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