#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }

    auto gao = [&](int delta) -> bool {
    	int mi = 0;
    	for (auto x : a){
    		if (mi == 0){
    			if (x + delta >= m) mi = 0;
    			else mi = x;
    		}
    		else {
    			if (x + delta >= mi + m) continue;
    			else if (x + delta >= mi) mi = max(mi, x);
    			else return false;
    		}
    	}
    	return true;
    };


    int l = 0, r = m;
    while(l < r){
    	int mid = (l + r) / 2;
    	if (gao(mid)) r = mid;
    	else l = mid + 1;
    }
    cout << l << "\n";


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}