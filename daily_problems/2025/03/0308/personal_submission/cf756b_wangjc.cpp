#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> cost(n + 1, INT_MAX);
    vector<int> dis(n + 1);
    cost[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> dis[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cost[i] = min(cost[i], cost[i - 1] + 20);
        int p = upper_bound(dis.begin(), dis.end(), dis[i] - 90) - dis.begin();
        if (p == 0) {
            cost[i] = min(cost[i], 50ll);
        } else cost[i] = min(cost[i], cost[p - 1] + 50);
        int pp = upper_bound(dis.begin(), dis.end(), dis[i] - 1440) - dis.begin();
        if (pp == 0) {
            cost[i] = min(cost[i], 120ll);
        } else cost[i] = min(cost[i], cost[pp - 1] + 120);
    }
    for (int i = 1; i <= n; i++) {
        cout << max(0ll, cost[i] - cost[i - 1]) << "\n";
    }
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
