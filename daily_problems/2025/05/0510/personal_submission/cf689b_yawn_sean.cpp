#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x, x --;
    
    vector<int> dis(n, -1);
    dis[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u && dis[u - 1] == -1) {
            dis[u - 1] = dis[u] + 1;
            q.push(u - 1);
        }

        if (u + 1 < n && dis[u + 1] == -1) {
            dis[u + 1] = dis[u] + 1;
            q.push(u + 1);
        }

        if (dis[nums[u]] == -1) {
            dis[nums[u]] = dis[u] + 1;
            q.push(nums[u]);
        }
    }

    for (auto &x: dis) cout << x << ' ';

    return 0;
}