#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    //for each station, leave the smallest to the final delivery
    vector<int> mi(n, n), cnt(n, 0);

    for (int i = 0; i < m; i++){
    	int a, b; cin >> a >> b;
    	a--; b--;
    	mi[a] = min(mi[a], (b - a + n) % n);
    	cnt[a]++;
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    		if (!cnt[j]) continue;
    		// cnt - 1 full cycle + shift + mi
    		res[i] = max(res[i], (cnt[j] - 1) * n + (j - i + n) % n + mi[j]);
    	}
    }
    for (int i = 0; i < n; i++){
    	cout << res[i] << " \n"[i == n - 1];
    }

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