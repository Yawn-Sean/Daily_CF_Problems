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

    int n, a, b;
    cin >> n >> a >> b;

    if (a && a == n - 1) cout << -1;
    else if (n == 1) cout << 1;
    else {
        if (b) b --, cout << "1 2 ";
        else cout << "2 1 ";

        int cur = 3, val = 2;
        for (int i = 2; i < n; i ++) {
            if (b) b --, val = cur + 1, cur += val;
            else if (a) a --, val = max(val + 1, 3);
            else val = 1;
            cout << val << ' ';
        }

    }

    return 0;
}