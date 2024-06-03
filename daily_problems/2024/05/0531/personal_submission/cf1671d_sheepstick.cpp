#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, x; cin >> n >> x;
    i64 res = 0;
    int mi = INT_MAX, mx = -1;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    	mi = min(mi, ai);
    	mx = max(mx, ai);
    }
    for (int i = 1; i < n; i++){
    	res += abs(a[i] - a[i - 1]);
    }

    if (mi > 1) res += min({a[0] - 1, a[n - 1] - 1, 2 * (mi - 1)});
    if (mx < x) res += min({x - a[0], x - a[n - 1], 2 * (x - mx)});
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