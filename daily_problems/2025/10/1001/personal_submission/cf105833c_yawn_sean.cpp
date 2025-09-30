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

    vector<int> hs(n), ds(n), cs(n);
    for (auto &h: hs) cin >> h;
    for (auto &d: ds) cin >> d;
    for (auto &c: cs) cin >> c;

    int inf = 1e9;

    vector<int> dp(5001, -inf);

    dp[0] = 0;

    for (int i = n - 1; i >= 0; i --) {
        for (int j = 5000; j >= 0; j --) {
            int nj = min(j + ds[i], 5000);
            dp[nj] = max(dp[nj], dp[j] - cs[i]);
        }

        for (int j = 0; j <= 5000; j ++)
            dp[j] += min(j, hs[i]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}