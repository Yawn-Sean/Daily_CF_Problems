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

    int c4, c7, c47, c74;
    cin >> c4 >> c7 >> c47 >> c74;

    if (abs(c47 - c74) > 1) cout << -1;
    else {
        vector<int> ans;
        if (c47 - c74 == 1 || (c47 == c74 && c4 >= c47 + 1 && c7 >= c47)) {
            for (int i = 0; i < c47; i ++) {
                ans.emplace_back(4);
                ans.emplace_back(7);
                c4 --, c7 --;
            }
            if (c47 == c74) ans.emplace_back(4), c4 --;
        }
        else {
            for (int i = 0; i < c74; i ++) {
                ans.emplace_back(7);
                ans.emplace_back(4);
                c4 --, c7 --;
            }
            if (c47 == c74) ans.emplace_back(7), c7 --;
        }

        if (c4 >= 0 && c7 >= 0) {
            vector<int> res;
            for (auto &x: ans) {
                if (x == 4)
                    while (c4) res.emplace_back(4), c4 --;
                res.emplace_back(x);
            }

            if (res.back() == 7)
                while (c7) res.emplace_back(7), c7 --;
            else {
                res.pop_back();
                while (c7) res.emplace_back(7), c7 --;
                res.emplace_back(4);
            }
            for (auto &x: res) cout << x;
        }
        else cout << -1;
    }

    return 0;
}