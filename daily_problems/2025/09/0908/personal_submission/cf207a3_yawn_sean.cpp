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

    vector<int> ks(n), a1s(n), xs(n), ys(n), ms(n);
    int sumk = 0;

    for (int i = 0; i < n; i ++)
        cin >> ks[i] >> a1s[i] >> xs[i] >> ys[i] >> ms[i], sumk += ks[i];
    
    int ans = 0;
    vector<vector<pair<int, int>>> tmp(200005);

    for (int i = 0; i < n; i ++) {
        int k = ks[i], a = a1s[i], x = xs[i], y = ys[i], m = ms[i];

        vector<int> vs = {a};
        for (int i = 1; i < k; i ++) {
            a = (1ll * a * x + y) % m;
            vs.emplace_back(a);
        }
        
        int c = 0;
        for (int j = 0; j < k; j ++) {
            if (j && vs[j] < vs[j - 1]) c ++;
            if (sumk <= 200000) tmp[c].emplace_back(vs[j], i + 1);
        }

        ans = max(ans, c);
    }

    cout << ans << '\n';

    if (sumk <= 200000) {
        for (auto &v: tmp) {
            sort(v.begin(), v.end());
            for (auto &[x, y]: v)
                cout << x << ' ' << y << '\n';
        }
    }

    return 0;
}