#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<vector<int>> contradictions(n + 1);
    while (m --) {
        int u, v;
        cin >> u >> v;
        contradictions[u].emplace_back(v);
        contradictions[v].emplace_back(u);
    }

    vector<int> vis(n + 1, 0);
    int l = 0;
    long long ans = 0;

    for (int r = 0; r < n; r ++) {
        vis[nums[r]] = 1;

        int cnt = 0;
        for (auto &x: contradictions[nums[r]])
            cnt += vis[x];
        
        while (cnt) {
            for (auto &x: contradictions[nums[l]])
                if (x == nums[r]) cnt --;
            vis[nums[l]] = 0;
            l ++;
        }

        ans += r - l + 1;
    }

    cout << ans;

    return 0;
}