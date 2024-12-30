#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, pn; cin >> n >> pn;

    vector<pair<int, int>> ns(n);
    
    for (int i = 0; i < n; i ++) {
        cin >> ns[i].second >> ns[i].first;
        ns[i].second --;
    }
    sort(ns.begin(), ns.end(), greater());

    long long ans = 1e18;

    for (int mxv = 0; mxv <= n; mxv ++) {
        long long cost = 0;
        vector<int> pcnt(pn);
        vector<int> vis(n);

        for (int i = 0 ; i < ns.size(); i ++) {
            auto [cur, pid] = ns[i];
            if (pid == 0) {
                pcnt[0] ++;
            } else if (pcnt[pid] < mxv) {
                pcnt[pid] ++;
                vis[i] = true;
            } else {
                pcnt[0] ++;
                cost += cur;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (pcnt[0] <= mxv && vis[i]) {
                pcnt[0] ++;
                cost += ns[i].first;
                vis[i] = false;
            }
        }

        if (pcnt[0] > mxv) {
            ans = min(ans, cost);
        }
    }

    cout << ans << '\n';

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}