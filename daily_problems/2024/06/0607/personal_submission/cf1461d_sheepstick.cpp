#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<i64> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    sort(a.begin(), a.end());
    set<i64> seen;

    vector<i64> sum(n + 1);
    for (int i = 0; i < n; i++){
    	sum[i + 1] = sum[i] + a[i];
    }


    auto gao = [&](auto self, int L, int R) -> void {
    	if (L >= R) return;
    	i64 tot = sum[R] - sum[L];
    	seen.insert(tot);

    	i64 mid = (a[L] + a[R - 1]) / 2;
    	auto idx = upper_bound(a.begin(), a.end(), mid) - a.begin();
    	if (idx >= R) return;
    	self(self, L, idx);
    	self(self, idx, R);
    };

    gao(gao, 0, n);
    while(q--){
    	i64 v; cin >> v;
    	if (seen.count(v)){
    		cout << "Yes\n";
    	}
    	else cout << "No\n";
    }


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