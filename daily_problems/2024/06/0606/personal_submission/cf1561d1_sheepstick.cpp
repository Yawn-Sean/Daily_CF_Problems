#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, mod; cin >> n >> mod;
    vector<int> vals(n + 5, 0), diff(n + 5, 0);

    auto add = [&](int &x, int y) -> void {
    	x = ((x + y) % mod + mod) % mod;
    };

    vals[n] = diff[n] = 1;

    for (int i = n - 1; i >= 1; i--){
    	vals[i] = diff[i + 1];
    	for (int j = 2; i * j <= n; j++){
    		int delta = diff[i * j];
    		if (j * (i + 1) <= n) add(delta, -diff[j * (i + 1)]);
    		add(vals[i], delta);
    	}
    	diff[i] = diff[i + 1];
    	add(diff[i], vals[i]);
    }



    cout << vals[1] << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}