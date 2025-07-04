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

    vector<pair<int, int>> intervals(n);
    for (auto &[l, r]: intervals) cin >> l >> r;

    int cur = -1;
    string s;

    auto dfs = [&] (auto &self, int u) -> int {
        s += '(';

        int val = 1;
        
        while (val < intervals[u].first && ++cur < n)
            val += self(self, cur);
        
        if (val < intervals[u].first || val > intervals[u].second)
            cout << "IMPOSSIBLE", exit(0);

        s += ')';

        return val + 1;
    };

    while (++cur < n)
        dfs(dfs, cur);
    
    cout << s;

    return 0;
}