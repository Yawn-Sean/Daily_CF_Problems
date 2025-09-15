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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> cubes(1000);
    for (int i = 0; i < 1000; i ++)
        cubes[i] = i * i * i;

    int q;
    cin >> q;

    while (q --) {
        int t;
        cin >> t;

        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            nums[idx - 1] = val;
        }
        else {
            int idx;
            cin >> idx;

            if (n - idx >= 1000) cout << n << '\n';
            else if (idx - 1 >= 1000) cout << 1 << '\n';
            else {
                idx --;
                int ans = -2;
                for (int i = 0; i < n; i ++) {
                    if (cubes[abs(i - idx)] >= nums[i]) {
                        ans = i;
                        break;
                    }
                }
                cout << ans + 1 << '\n';
            }
        }
    }

    return 0;
}