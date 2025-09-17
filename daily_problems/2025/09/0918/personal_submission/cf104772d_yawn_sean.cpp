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

    int d, saved;
    cin >> d;

    saved = d;

    while (d % 2 == 0) d /= 2;
    while (d % 5 == 0) d /= 5;

    int cur = 0, tot = 0;

    for (int i = 1; i <= 1000000; i ++) {
        cur = (10ll * cur + 9) % d;
        tot = (tot + 9) % saved;

        if (cur == 0 && tot == 0)
            return cout << string(i, '9') << string(10, '0'), 0;
    }

    return 0;
}