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
        long long p;
        cin >> p;

        vector<int> ans;
        
        for (int b = 1; b <= 1'000'000; b ++) {
            if ((p - 1) % (b + 1) == 0 && 2 * (p - 1) % (b + 2) == 0) {
                ans.emplace_back(b);
            }
        }
        
        for (int k = 1; k <= 2'000'000; k ++) {
            if (2 * (p - 1) % k == 0) {
                long long v = 2 * (p - 1) / k;
                long long b = sqrtl(4 * v + 1);

                while (b * b < 4 * v + 1) b ++;
                while (b * b > 4 * v + 1) b --;

                b = (b - 1) / 2 - 1;
                if (b > 0 && (p - 1) % (b + 1) == 0 && 2 * (p - 1) % (b + 2) == 0) {
                    ans.emplace_back(b);
                }
            }
        }

        sort(ans.begin(), ans.end());
        int k = unique(ans.begin(), ans.end()) - ans.begin();
        cout << k << '\n';
        for (int i = 0; i < k; i ++) cout << ans[i] << ' '; cout << '\n';
    }

    return 0;
}