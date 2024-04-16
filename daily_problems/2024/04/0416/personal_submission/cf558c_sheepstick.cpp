#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 17;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    vector<int> cost(1 << M, 0), cnt(1 << M, 0);

    for (auto v : a){
    	for (int r = 0; (v >> r) > 0; r++){
    		cost[(v >> r)] += r;
    		cnt[(v >> r)]++;
    		if (!r || (1 & (v >> (r - 1)))){
    			for (int l = 1; ((v >> r) << l) < 1 << M; l++){
    				cost[(v >> r) << l] += r + l;
    				cnt[(v >> r) << l]++;
    			}
    		}
    	}
    }
    int res = INT_MAX;
    for (int i = 1; i < (1 << M); i++){

    	if (cnt[i] == n) res = min(res, cost[i]);
    }
    cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}