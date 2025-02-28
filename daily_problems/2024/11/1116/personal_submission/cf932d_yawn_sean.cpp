#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, cur = 1, last = 0;
    cin >> q;

    int inf_int = 2e9;
    long long inf_long = 2e15;

    vector<vector<int>> parent(20, vector<int>(q + 5, 0)), parent_weight(20, vector<int>(q + 5, 0)), chain_parent(20, vector<int>(q + 5, 0));
    vector<vector<long long>> chain_parent_weight(20, vector<long long>(q + 5, 0));

    for (int i = 0; i < 20; i ++) {
        parent_weight[i][0] = inf_int;
        chain_parent_weight[i][0] = inf_long;
        if (i) chain_parent_weight[i][1] = inf_long;
    }

    chain_parent_weight[0][1] = 0;

    while (q --) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, q;
            cin >> p >> q;

            p ^= last;
            q ^= last;

            cur ++;
            int u = cur;

            parent[0][u] = p;
            parent_weight[0][u] = q;
            chain_parent[0][u] = p;
            chain_parent_weight[0][u] = q;

            for (int i = 1; i < 20; i ++) {
                p = parent[i - 1][u];
                parent[i][u] = parent[i - 1][p];
                parent_weight[i][u] = max(parent_weight[i - 1][u], parent_weight[i - 1][p]);
            }

            for (int i = 19; i >= 0; i --)
                if (parent_weight[i][chain_parent[0][u]] < q)
                    chain_parent[0][u] = parent[i][chain_parent[0][u]];
            
            for (int i = 1; i < 20; i ++) {
                p = chain_parent[i - 1][u];
                chain_parent[i][u] = chain_parent[i - 1][p];
                chain_parent_weight[i][u] = chain_parent_weight[i - 1][u] + chain_parent_weight[i - 1][p];
                if (chain_parent_weight[i][u] > inf_long) {
                    for (int j = i; j < 20; j ++) {
                        chain_parent_weight[j][u] = inf_long;
                    }
                    break;
                }
            }
        }
        else {
            int p;
            long long q;
            cin >> p >> q;

            p ^= last;
            q ^= last;

            last = 0;

            for (int i = 19; i >= 0; i --) {
                if (q >= chain_parent_weight[i][p]) {
                    q -= chain_parent_weight[i][p];
                    p = chain_parent[i][p];
                    last |= 1 << i;
                }
            }
            cout << last << '\n';
        }
    }

    return 0;
}