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
        int n;
        cin >> n;

        if (n < 6) {
            cout << n / 2 + 1 << '\n';
            for (int i = 1; i <= n; i ++)
                cout << i / 2 + 1 << ' ';
            cout << '\n';
        }
        else {
            cout << 4 << '\n';
            for (int i = 1; i <= n; i ++)
                cout << i % 4 + 1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}