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

    int n, m;
    cin >> n >> m;

    vector<__int128_t> neighbors(n, 0);
    vector<int> cnt(n, 0);

    __int128_t one = 1;

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        neighbors[u] |= one << v + 1;
        neighbors[v] |= one << u + 1;

        cnt[u] ^= 1;
        cnt[v] ^= 1;
    }

    for (int i = 0; i < n; i ++) {
        if (cnt[i]) neighbors[i] |= one << i + 1;
        else neighbors[i] |= 1;
    }

    vector<__int128_t> base(n + 1, 0);

    for (auto &x: neighbors) {
        for (int i = n; i >= 0; i --) {
            if (x >> i & 1) {
                if (base[i]) x ^= base[i];
                else {
                    base[i] = x;
                    break;
                }
            }
        }
    }

    cout << (base[0] ? 'N' : 'Y');

    return 0;
}