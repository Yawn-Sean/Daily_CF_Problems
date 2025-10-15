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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cur(n);
    for (auto &x: cur) cin >> x;

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i ++)
        pos[cur[i]] = i;
    
    long long ans = 0;
    while (m --) {
        int i;
        cin >> i;

        ans += pos[i] / k + 1;
        if (pos[i]) {
            int p = pos[i];
            swap(pos[cur[p]], pos[cur[p - 1]]);
            swap(cur[p], cur[p - 1]);
        }
    }

    cout << ans;

    return 0;
}