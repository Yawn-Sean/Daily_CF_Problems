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

    long long n;
    cin >> n;

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((n + mid) / 3 >= 1ll * mid * (mid + 1) / 2)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << (r + n % 3) / 3;

    return 0;
}