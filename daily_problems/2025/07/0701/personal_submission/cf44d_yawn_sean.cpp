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

    vector<int> xs(n), ys(n), zs(n);
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> ys[i] >> zs[i];
    
    long double ans = 1e8;

    auto dis = [&] (int i, int j) -> long double {
        return powl((xs[i] - xs[j]) * (xs[i] - xs[j]) + 
                    (ys[i] - ys[j]) * (ys[i] - ys[j]) + 
                    (zs[i] - zs[j]) * (zs[i] - zs[j]), 0.5);
    };

    for (int i = 1; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            ans = min(ans, dis(0, i) + dis(0, j) + dis(i, j));
        }
    }

    cout << fixed << setprecision(15) << ans / 2;

    return 0;
}