#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; ++i) {  
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[i] = {u, v};
    }


    if (n <= 6) {
        cout << m << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // {i, j}用同一个数字的domino
                // eg. [1,1],[2,2],...
                set<pair<int, int>> used;
                for (auto& [u, v]: edges) {
                    int num_u = u, num_v = v;
                    if (u == i) {
                        num_u = j;
                    }
                    if (v == i) {
                        num_v = j;
                    }
                    if (num_u > num_v) {
                        swap(num_u, num_v);
                    }
                    used.insert({num_u, num_v});
                }
                ans = max(ans, (int)used.size());
            }
        }
        cout << ans << endl;
    }
    return 0;
}
