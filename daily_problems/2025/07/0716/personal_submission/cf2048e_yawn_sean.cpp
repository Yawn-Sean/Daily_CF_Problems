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
        int n, m;
        cin >> n >> m;
        if (m >= 2 * n) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < 2 * n; i ++) {
                for (int j = 0; j < m; j ++) {
                    cout << (i + j) % (2 * n) / 2 + 1 << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}