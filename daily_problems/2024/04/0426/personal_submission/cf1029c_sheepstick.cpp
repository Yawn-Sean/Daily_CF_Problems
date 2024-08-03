#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> l{{INT_MIN, -1}, {INT_MIN, -1}}, r{{INT_MAX, -1}, {INT_MAX, -1}};
    vector<array<int,2>> seg(n);
    for (int i = 0; i < n; i++){
    	cin >> seg[i][0] >> seg[i][1];
    	if (seg[i][0] > l[1].first){
    		l[1] = {seg[i][0], i};
    	}
    	if (seg[i][1] < r[1].first){
    		r[1] = {seg[i][1], i};
    	}
    	if (l[1] > l[0]) swap(l[1], l[0]);
    	if (r[1] < r[0]) swap(r[1], r[0]);
    }

    int res = 0;
    for (int i = 0; i < n; i++){
    	int L = l[0].second == i ? l[1].first : l[0].first;
    	int R = r[0].second == i ? r[1].first : r[0].first;
    	res = max(res, R - L);
    }
    cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}