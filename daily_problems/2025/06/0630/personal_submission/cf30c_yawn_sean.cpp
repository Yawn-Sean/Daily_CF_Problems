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

struct node {
    int x, y, t;
    long double p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<node> nodes(n);
    for (auto &v: nodes)
        cin >> v.x >> v.y >> v.t >> v.p;
    
    sort(nodes.begin(), nodes.end(), [&] (node x, node y) {
        return x.t < y.t;
    });

    vector<long double> dp(n, 0);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if ((nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) +
                (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y) <=
                1ll * (nodes[i].t - nodes[j].t) * (nodes[i].t - nodes[j].t))
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += nodes[i].p;
    }

    cout << fixed << setprecision(15) << *max_element(dp.begin(), dp.end());

    return 0;
}