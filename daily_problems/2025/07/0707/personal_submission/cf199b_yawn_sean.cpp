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

    int x1, y1, r1, R1, x2, y2, r2, R2;
    cin >> x1 >> y1 >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;

    int v = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

    auto check = [&] (int r0, int r, int R) -> int {
        if (r >= r0 && (r - r0) * (r - r0) >= v) return 1;
        if (R <= r0 && (R - r0) * (R - r0) >= v) return 1;
        if ((R + r0) * (R + r0) <= v) return 1;
        return 0;
    };

    cout << check(r1, r2, R2) + check(R1, r2, R2) + check(r2, r1, R1) + check(R2, r1, R1);

    return 0;
}