#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using i64 = long long;
const int INF = 1 << 30;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

void solve() {
    int n; cin >> n;
    orderedSet rbt;
    i64 res = 0;
    for (int i = 0; i < n; i++){
    	int x; cin >> x;
    	int l = rbt.order_of_key(make_pair(x, -INF));
    	int r = i - rbt.order_of_key(make_pair(x + 1, -INF));
    	res += min(l, r);
    	rbt.insert(make_pair(x, i));
    }
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