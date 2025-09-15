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

    map<long long, int> mp;
    while (n --) {
        long long x;
        cin >> x;
        mp[x] ++;
    }

    int c1 = mp[1], c2 = mp[2], c4 = mp[4];

    long long ans = 1ll * c1 * (c1 - 1) * c2;

    for (auto &[k, v]: mp) {
        if (k <= 2) continue;

        if (k == 3) ans += 2ll * v * c1 * c2;
        else if (k == 4) {
            ans += 1ll * v * c2 * (c2 - 1);
            if (mp.find(3) != mp.end()) ans += 2ll * v * c1 * mp[3];
        }
        else {
            if (mp.find(k - 1) != mp.end()) ans += 2ll * v * c1 * mp[k - 1];
            if (mp.find(k - 2) != mp.end()) ans += 2ll * v * c2 * mp[k - 2];
            if (k >= 7 && mp.find(k - 4) != mp.end()) ans += 2ll * v * c4 * mp[k - 4];
        }
    }

    cout << ans;

    return 0;
}