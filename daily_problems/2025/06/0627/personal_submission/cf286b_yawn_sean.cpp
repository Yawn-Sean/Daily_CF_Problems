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

    vector<int> ans(2 * n, 0);
    iota(ans.begin(), ans.begin() + n, 1);

    for (int i = 0; i < n; i ++) {
        int cur = 0;
        for (int j = 0; j < n; j += i + 1)
            swap(ans[i + j], cur);
        ans[i + n] = cur;
    }

    for (int i = 0; i < n; i ++)
        cout << ans[i + n] << ' ';

    return 0;
}