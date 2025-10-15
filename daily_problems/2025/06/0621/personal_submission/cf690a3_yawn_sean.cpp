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
        int n, r;
        cin >> n >> r;

        for (int i = 0; i < n - 1; i ++) {
            int x;
            cin >> x;
            r -= x;
            if (r <= 0) r += n;
        }
        
        cout << r << '\n';
    }

    return 0;
}