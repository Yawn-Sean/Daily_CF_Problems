#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/mincostflow.hpp"

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

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    vector<int> nums1(n), nums2(m);
    int s1 = 0, s2 = 0;

    for (auto &x: nums1) cin >> x, s1 += x;
    for (auto &x: nums2) cin >> x, s2 += x;

    if (s1 != s2) return cout << -1, 0;

    atcoder::mcf_graph<int, int> mcf(n + m + 2);
    int src = n + m, dst = src + 1;

    for (int i = 0; i < n; i ++)
        mcf.add_edge(src, i, nums1[i], 0);
    
    for (int j = 0; j < m; j ++)
        mcf.add_edge(n + j, dst, nums2[j], 0);
    
    int total = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j]) mcf.add_edge(i, n + j, 1, 0), total ++;
            else mcf.add_edge(i, n + j, 1, 2);
        }
    }

    auto res = mcf.flow(src, dst);

    if (res.first == s1) cout << res.second + (total - s1);
    else cout << -1;

    return 0;
}