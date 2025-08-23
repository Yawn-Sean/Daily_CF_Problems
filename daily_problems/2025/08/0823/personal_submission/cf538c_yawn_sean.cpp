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

    vector<pair<int, int>> notes(m);
    for (auto &[x, y]: notes) cin >> x >> y;

    int ans = max(notes[0].first - 1 + notes[0].second,
                  n - notes.back().first + notes.back().second);
    
    for (int i = 1; i < m; i ++) {
        auto [d1, h1] = notes[i - 1];
        auto [d2, h2] = notes[i];
        if (abs(h1 - h2) > d2 - d1) return cout << "IMPOSSIBLE", 0;
        ans = max(ans, (h1 + h2 + d2 - d1) / 2);
    }

    cout << ans;

    return 0;
}