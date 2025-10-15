#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> path(n);
    vector<int> ind(n);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        path[u].push_back(v);
        path[v].push_back(u);
        ++ind[u];
        ++ind[v];
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> nums(n, 1);
    for (int i = 0; i < n; i++) {
        if (ind[i] == 1) {
            pq.push({1, i});
        }
    }

    while (!pq.empty()) {
        auto pr = pq.top();
        pq.pop();
        
        int u = pr.second;
        for (auto&v: path[u]) {
            if (nums[v] > 0) {
                if (nums[v] < nums[u]) {
                    cout << "NO\n";
                    return 0;
                }
                nums[v] += nums[u];
                nums[u] = 0;
                --ind[v];
                if (ind[v] == 1) {
                    pq.push({nums[v], v});
                }
            }
        }
    }

    cout << "YES\n";
    return 0;
}
