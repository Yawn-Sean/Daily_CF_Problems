#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    int res = INT_MAX, pos = -1;
    for (int i = k; i < n; i++){
    	int v = (a[i] - a[i - k] + 1) / 2;
    	if (v < res){
    		res = v;
    		pos = a[i - k] + v;
    	}
    }
    cout << pos << "\n";

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