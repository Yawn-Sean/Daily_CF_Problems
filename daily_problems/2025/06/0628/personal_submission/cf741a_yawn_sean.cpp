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

    vector<int> perm(n);
    for (auto &v: perm)
        cin >> v, v --;

    vector<bool> vis(n, 0);
    int ans = 1;

    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            int x = i, c = 0;
            while (!vis[x]) {
                vis[x] = 1;
                x = perm[x];
                c ++;
            }
            if (x != i) return cout << -1, 0;

            if (c % 2 == 0) c /= 2;
            ans = 1ll * ans * c / gcd(ans, c);
        }
    }

    cout << ans;

    return 0;
}