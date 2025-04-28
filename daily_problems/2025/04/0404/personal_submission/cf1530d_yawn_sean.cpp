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

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n + 1), cnt(n + 1, 0);
        for (int i = 1; i <= n; i ++) {
            cin >> nums[i];
            cnt[nums[i]] ++;
        }

        vector<int> target, position;
        for (int i = 1; i <= n; i ++)
            if (!cnt[i]) target.emplace_back(i);
        
        for (int i = 1; i <= n; i ++) {
            cnt[nums[i]] --;
            if (cnt[nums[i]])
                position.emplace_back(i);
        }

        int k = position.size();
        cout << n - k << '\n';

        if (k > 1) {
            while (true) {
                shuffle(position.begin(), position.end(), rng);

                bool flg = true;
                for (int i = 0; i < k; i ++) {
                    if (target[i] == position[i]) {
                        flg = false;
                    }
                }

                if (flg) break;
            }

            for (int i = 0; i < k; i ++)
                nums[position[i]] = target[i];
        }

        else if (k == 1) {
            if (position[0] == target[0]) {
                for (int i = 1; i <= n; i ++) {
                    if (i != position[0] && nums[i] == nums[position[0]]) {
                        nums[i] = target[0];
                    }
                }
            }
            else nums[position[0]] = target[0];
        }

        for (int i = 1; i <= n; i ++)
            cout << nums[i] << ' ';
        cout << '\n';
    }

    return 0;
}