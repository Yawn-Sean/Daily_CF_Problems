#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<i64> a(n), acc(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    sort(a.rbegin(), a.rend());
    partial_sum(a.begin(), a.end(), acc.begin());

    vector<i64> res(n, 0);
    for (int i = 1; i <= n - 1; i++){
    	i64 idx = 1, itv = i, w = 1;
    	while(idx < n){
    		res[i] += w * (acc[min(idx + itv - 1, n - 1LL)] - acc[idx - 1]);
    		idx += itv;
    		itv *= i;
    		w ++;
    	}
    }
    int q; cin >> q;
    while(q--){
    	int k; cin >> k;
    	k = min(k, n - 1);
    	cout << res[k] << " ";
    }
    cout << "\n";



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}