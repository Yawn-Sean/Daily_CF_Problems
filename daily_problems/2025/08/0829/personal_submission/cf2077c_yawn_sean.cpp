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

    int mod = 998244353, M = 2e5;
    vector<int> pw2(M + 1, 1);

    for (int i = 1; i <= M; i ++)
        pw2[i] = 1ll * pw2[i - 1] * 2 % mod;
    
    int rev4 = ((mod + 1) / 2 + mod) / 2;

    while (t --) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        int c0 = 0, c1 = 0;

        for (auto &c: s) {
            if (c == '0') c0 ++;
            else c1 ++;
        }

        while (q --) {
            int idx;
            cin >> idx;
            idx --;

            if (s[idx] == '0') {
                c0 --, c1 ++;
                s[idx] = '1';
            }
            else {
                c1 --, c0 ++;
                s[idx] = '0';
            }

            cout << ((1ll * c0 * (c0 + 1) / 2 % mod + 1ll * c1 * (c1 + 1) / 2 % mod - 1ll * c0 * c1 % mod - 1) % mod * pw2[n - 1] % mod * rev4 % mod + mod) % mod << '\n';
        }
    }

    return 0;
}