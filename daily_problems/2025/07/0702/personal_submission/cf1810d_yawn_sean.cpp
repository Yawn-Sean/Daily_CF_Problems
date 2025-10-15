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

    auto f = [&] (long long x, int a, int b) -> long long {
        if (x <= a) return 1;
        return (x - a - 1) / (a - b) + 2;
    };

    while (t --) {
        int q;
        cin >> q;

        long long l = -1, r = 1e18;

        while (q --) {
            int qtype;
            cin >> qtype;

            if (qtype == 1) {
                int a, b, n;
                cin >> a >> b >> n;

                long long nl, nr;
                if (n == 1) nl = 1, nr = a;
                else nl = 1ll * (a - b) * (n - 2) + a + 1, nr = 1ll * (a - b) * (n - 1) + a;
                
                if (max(l, nl) <= min(r, nr))
                    l = max(l, nl), r = min(r, nr), cout << "1 ";
                else cout << "0 ";
            }

            else {
                int a, b;
                cin >> a >> b;

                long long v1 = f(l, a, b), v2 = f(r, a, b);
                cout << (v1 == v2 ? v1 : -1) << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}