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
    long long l;
    cin >> n >> l;
    l ++;

    vector<int> vals(16);
    while (n --) {
        int x;
        cin >> x;
        vals[x] = 1;
    }

    set<long long> vis = {1};

    auto dfs = [&] (auto &self, long long cur) -> void {
        for (int i = 2; i < 16; i ++) {
            if (vals[i]) {
                long long ncur = cur * (i + 1);
                if (ncur <= l && vis.find(ncur) == vis.end()) {
                    vis.insert(ncur);
                    self(self, ncur);
                }
            }
        }
    };

    dfs(dfs, 1);

    cout << vis.size() - 1;

    return 0;
}