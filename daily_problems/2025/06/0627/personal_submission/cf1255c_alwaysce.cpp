#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    map<pair<int,int>, vector<int>> mp;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n - 2; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        vector<int> tmp = {u, v, w};
        sort(tmp.begin(), tmp.end());
        
        u = tmp[0], v = tmp[1], w = tmp[2];

        mp[{u, v}].push_back(w);
        mp[{u, w}].push_back(v);
        mp[{v, w}].push_back(u);
        ++cnt[u];
        ++cnt[v];
        ++cnt[w];
    }

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 1) {
            vector<int> ans = {i};
            for (auto& [k, _]: mp) {
                auto [u, v] = k;
                if (u == i && cnt[v] == 2) {
                    ans.emplace_back(v);
                    break;
                }
                if (v == i && cnt[u] == 2) {
                    ans.emplace_back(u);
                    break;
                }
            }

            for (int j = 0; j < n - 2; j++) {
                int u = ans[j], v = ans[j + 1];
                if (u > v) { swap(u, v); }

                for (auto&w: mp[{u, v}]) {
                    if (j == 0 || ans[j - 1] != w) {
                        ans.emplace_back(w);
                        break;
                    }
                }
            }

            for (auto&x: ans) {
                cout << x << ' ';
            }
            break;
        }
    }

    return 0;
}
