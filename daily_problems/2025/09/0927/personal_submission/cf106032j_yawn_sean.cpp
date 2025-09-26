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

    int t, inf = 1e9;
    cin >> t;

    while (t --) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> nums(n), cnt(m + 1, 0);
        for (auto &x: nums)
            cin >> x, cnt[x] ^= 1;
        
        vector<int> next_odd(m + 1, inf);

        for (int i = 0; i <= m; i ++)
            if (cnt[i]) next_odd[i] = 0;
        
        for (int i = m; i > 0; i --)
            next_odd[i - 1] = min(next_odd[i - 1], next_odd[i] + 1);
        
        next_odd[m] = min(next_odd[m], next_odd[0]);
        for (int i = m; i > 0; i --)
            next_odd[i - 1] = min(next_odd[i - 1], next_odd[i] + 1);

        int c = 0;
        while (q --) {
            int t;
            cin >> t;
            if (t == 1) c ++;
            else {
                int idx;
                cin >> idx;

                int x = nums[idx - 1], step = min(c, next_odd[x]);
                cout << (x + step - 1) % m + 1 << '\n';
            }
        }
    }

    return 0;
}