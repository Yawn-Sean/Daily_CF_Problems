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

    int la, lb;
    cin >> la >> lb;

    vector<int> numsa(la), numsb(lb);
    for (auto &v: numsa) cin >> v;
    for (auto &v: numsb) cin >> v;

    vector<int> pos(1000001, -1);
    for (int i = 0; i < lb; i ++)
        pos[numsb[i]] = i;
    
    int ans = 0, cur = 0, ncur, r = 0;

    for (int i = 0; i < la; i ++) {
        if (r < i) {
            r = i;
            cur = 0;
        }
        else if (i > 0) {
            ncur = pos[numsa[i]] - pos[numsa[i - 1]];
            if (ncur < 0) ncur += lb;
            cur -= ncur;
        }

        if (pos[numsa[i]] == -1) continue;

        while (r < i + la - 1) {
            if (pos[numsa[(r + 1) % la]] == -1) break;
            ncur = pos[numsa[(r + 1) % la]] - pos[numsa[r % la]];
            if (ncur < 0) ncur += lb;
            if (cur + ncur >= lb) break;
            r ++;
            cur += ncur;
        }

        ans = max(ans, r - i + 1);
    }
    cout << ans;

    return 0;
}