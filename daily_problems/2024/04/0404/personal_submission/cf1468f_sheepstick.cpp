#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    i64 res = 0;
    map<pair<int,int>,int> mp;
    for (int i = 0; i < n; i++){
    	int x, y, u, v; cin >> x >> y >> u >> v;
    	int dx = u - x, dy = v - y;
		int g = __gcd(abs(dx), abs(dy));
		dx /= g;
		dy /= g;
		//check reverse direction
		res += mp[{-dx, -dy}];
		mp[{dx, dy}]++;
    }
    cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}