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

    int dp1 = 0, dp2 = 0, dp3 = 0;

    while (n --) {
        int x;
        cin >> x;
        
        dp3 = max(dp2, dp3) - x;
        dp2 = max(dp1, dp2) + x;
        dp1 -= x;
    }

    cout << max(dp2, dp3);

    return 0;
}