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

    int t;
    cin >> t;

    while (t --) {
        int a, b;
        cin >> a >> b;

        if ((a | b) != a) cout << -1 << '\n';
        else if ((a & -a) == a && b == 0 && a) cout << -1 << '\n';
        else {
            vector<int> ans;
            int xor_val = b;

            for (int i = 0; i <= a; i ++) {
                if ((i & a) == i) {
                    ans.emplace_back(i);
                    xor_val ^= i;
                }
            }

            int ans_len = ans.size();
            if (!xor_val) xor_val = -1;
            else ans_len --;

            cout << ans_len << '\n';
            for (auto &x: ans) if (x != xor_val) cout << x << ' '; cout << '\n';
        }
    }

    return 0;
}