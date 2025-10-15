#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<vector<int>> cnt(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x].push_back(i);
    }

    if (cnt[0].size() != 1) {
        cout << -1;
        return 0;
    }

    int node = cnt[0][0];
    vector<int> deg(n + 1, 0);
    queue<int> q;
    q.push(node);
    
    vector<pair<int,int>> ans;
    for (int i = 1; i < n; i++) {
        queue<int> nq;
        while (!cnt[i].empty() && !q.empty()) {
            int u = q.front();
            q.pop();

            while (!cnt[i].empty() && deg[u] < k) {
                int cur = cnt[i].back();
                cnt[i].pop_back();

                ans.emplace_back(u, cur);
                ++deg[u];
                ++deg[cur];
                nq.push(cur);
            }

        }

        if (!cnt[i].empty()) {
            cout << -1;
            return 0;
        }
        q = nq;
    }

    cout << ans.size() << "\n";
    for (auto& [u, v] : ans) {
        cout << u << " " << v << "\n";
    }
    return 0;
}
