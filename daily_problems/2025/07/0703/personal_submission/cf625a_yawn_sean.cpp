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

    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long ans = 0;
    if (n >= b && b - c <= a) {
        ans = (n - b) / (b - c) + 1;
        n -= ans * (b - c);
    }

    ans += n / a;
    cout << ans;

    return 0;
}