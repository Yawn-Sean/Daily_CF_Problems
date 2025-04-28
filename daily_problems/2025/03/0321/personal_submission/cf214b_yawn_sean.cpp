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

    int n;
    cin >> n;

    vector<int> cnt(10, 0);
    int total = 0;

    while (n --) {
        int x;
        cin >> x;
        cnt[x] ++;
        total += x;
    }

    auto print_answer = [&] () -> void {
        bool flg = false;
        for (int i = 9; i > 0; i --) {
            for (int j = 0; j < cnt[i]; j ++) {
                cout << i;
                flg = true;
            }
        }
        if(!flg) cout << 0;
        else {
            for (int j = 0; j < cnt[0]; j ++) {
                cout << 0;
            }
        }
    };

    if (!cnt[0]) cout << -1;
    else if (total % 3 == 0) print_answer();
    else {
        for (int i = 0; i < 10; i ++) {
            if (cnt[i] && (total - i) % 3 == 0) {
                cnt[i] --;
                print_answer();
                return 0;
            }
        }

        for (int i = 0; i < 10; i ++) {
            if (cnt[i]) {
                cnt[i] --;
                for (int j = 0; j <= i; j ++) {
                    if (cnt[j] && (total - i - j) % 3 == 0) {
                        cnt[j] --;
                        print_answer();
                        return 0;
                    }
                }
                cnt[i] ++;
            }
        }
    }

    return 0;
}