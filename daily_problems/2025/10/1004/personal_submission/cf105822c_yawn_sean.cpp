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
        string s;
        cin >> n >> s;

        int ce = 0;
        for (auto &c: s) {
            if (c == 'E') {
                ce ^= 1;
            }
        }

        if (ce) cout << "NO\n";
        else {
            cout << "YES\n";
            int pt1 = 1, pt2 = 2;
            for (auto &c: s) {
                if (c == 'O') {
                    cout << pt1 << ' ' << pt2 << '\n';
                    pt1 += 2;
                    pt2 += 2;
                }
                else {
                    if (pt1 < pt2) cout << pt1 << ' ' << pt1 + 2 << '\n', pt1 += 4;
                    else cout << pt2 << ' ' << pt2 + 2 << '\n', pt2 += 4;
                }
            }
        }
    }

    return 0;
}