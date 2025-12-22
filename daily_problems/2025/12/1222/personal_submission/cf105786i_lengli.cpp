#include <bits/stdc++.h>
using namespace std;

static const int M = 300000;

int pr[M + 1];
int vis[M + 1];
int vis_target[M + 1];

// 获取 x 的不重复质因子
vector<int> get_prime_factors(int x) {
    vector<int> ans;
    while (x > 1) {
        int p = pr[x];
        ans.push_back(p);
        while (x % p == 0) x /= p;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 预处理最小质因子
    for (int i = 1; i <= M; i++) pr[i] = i;
    for (int i = 2; i <= M; i++) {
        if (pr[i] == i) {
            for (int j = i; j <= M; j += i) {
                pr[j] = i;
            }
        }
    }

    int t;
    cin >> t;

    vector<int> outs;
    outs.reserve(t);

    // 初始化标记数组
    fill(vis, vis + M + 1, -1);
    fill(vis_target, vis_target + M + 1, -1);

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        int ans = 0;
        int to_delete = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            auto tmp = get_prime_factors(x);

            bool flg = true;
            int pos = i;

            for (int v : tmp) {
                if (vis[v] != -1) {
                    pos = min(pos, vis[v]);
                    flg = false;
                } else {
                    vis[v] = i;
                }
            }

            if (flg) {
                ans++;
                for (int v : tmp) {
                    vis_target[v] = i;
                }
            } else {
                unordered_set<int> nvis;
                for (int v : tmp) {
                    if (vis_target[v] > pos) {
                        nvis.insert(vis_target[v]);
                    }
                }
                to_delete = max(to_delete, (int)nvis.size());
            }
        }

        outs.push_back(ans - to_delete);

        // 清理 vis / vis_target
        for (int x : nums) {
            auto tmp = get_prime_factors(x);
            for (int v : tmp) {
                vis[v] = -1;
                vis_target[v] = -1;
            }
        }
    }

    // 输出
    for (int x : outs) {
        cout << x << '\n';
    }

    return 0;
}
