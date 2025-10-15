#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        
    */
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(k);
        for (auto&v: nums) {
            cin >> v;
        }

        vector<vector<int>> path(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            path[u].push_back(v);
            path[v].push_back(u);
        }

        vector<int> note(n + 1), cur_path;

        // 相遇点之下的子树是不可以到达的
        function<void(int, int)> dfs = [&](int u, int p) {
            cur_path.emplace_back(u);
            // 从1->note[u]<-u出发 note[u]的相遇点
            note[u] = cur_path[cur_path.size() / 2];
            for (auto& v: path[u]) {
                if (v != p) {
                    dfs(v, u);
                }
            }
            cur_path.pop_back();
        };

        dfs(1, 0);

        vector<int> control(n + 1);
        for (auto& v: nums) {
            control[note[v]] = 1;
        }
        int cnt = 0;

        function<void(int,int)> dfs1 = [&](int u, int p) {
            if (control[u]) {
                ++cnt;
                return;
            }
            // 到达了叶子 说明1-win
            if (u != 1 && path[u].size() == 1) {
                cnt = n + 1;
                return;
            }
            for (auto& v: path[u]) {
                if (v != p) {
                    dfs1(v, u);
                }
            }
        };

        dfs1(1, 0);
        cout << (cnt <= k ? cnt : -1) << '\n';
    }
    
    return 0;
}
