#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
#include "atcoder/fenwicktree"
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

// Let's set a bit and flow!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n), pos(n + 2);
    for (int i = 0; i < n; i ++)
        cin >> nums[i], pos[nums[i]] = i;
    
    pos[0] = -1, pos[n + 1] = n;
    atcoder::fenwick_tree<int> fen(n + 1);

    for (int i = 0; i <= n; i ++)
        if (pos[i] > pos[i + 1]) fen.add(i, 1);
    
    int q;
    cin >> q;

    while (q --) {
        int p, x, y;
        cin >> p >> x >> y;

        if (p == 2) {
            x --;
            y --;

            int vx = nums[x], vy = nums[y];
            set<int> to_check;
            for (int i = 0; i < 2; i ++) {
                to_check.emplace(vx - i);
                to_check.emplace(vy - i);
            }

            for (auto &i: to_check) {
                if (pos[i] > pos[i + 1]) {
                    fen.add(i, -1);
                }
            }

            swap(pos[vx], pos[vy]);
            swap(nums[x], nums[y]);

            for (auto &i: to_check) {
                if (pos[i] > pos[i + 1]) {
                    fen.add(i, 1);
                }
            }
        }
        else {
            cout << fen.sum(x, y) + 1 << '\n';
        }
    }

    return 0;
}