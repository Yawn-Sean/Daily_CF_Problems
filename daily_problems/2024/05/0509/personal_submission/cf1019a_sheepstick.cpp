#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> parties(m, 0);
    vector<array<int,2>> state;
    for (int i = 0; i < n; i++){
    	int p, c; cin >> p >> c;
    	parties[--p]++;
    	if (p) state.push_back({c, p});
    }
    if (parties[0] >= n / 2 + 1) {
    	cout << "0\n";
    	return;
    }

    sort(state.begin(), state.end());
    int sz = state.size();

    i64 ans = 1LL << 60;

    for (int i = parties[0]; i <= n / 2 + 1; i++){
    	i64 res = 0;
    	int need = i - parties[0];
    	vector<int> visited(sz, 0), rem(m, 0);
    	for (int j = 0; j < sz; j++){
    		auto [cost, vote] = state[j];
    		if (parties[vote] - rem[vote] >= i){
    			rem[vote]++;
    			res += cost;
    			visited[j] = 1;
    			need--;
    		}
    	}

    	for (int j = 0; j < sz && need > 0; j++){
    		if (visited[j]) continue;
    		res += state[j][0];
    		need--;
    	}
    	ans = min(ans, res);
    }
    cout << ans << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}