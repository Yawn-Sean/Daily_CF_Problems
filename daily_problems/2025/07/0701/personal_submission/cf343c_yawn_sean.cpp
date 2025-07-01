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

    vector<long long> heads(n), reads(m);
    for (auto &v: heads) cin >> v;
    for (auto &v: reads) cin >> v;

    long long l = 0, r = 1e12;

    while (l <= r) {
        long long mid = (l + r) / 2;
        int pt = 0;

        for (auto &h: heads) {
            long long target = 0;
            if (h <= reads[pt]) target = h + mid;
            else if (h - reads[pt] <= mid)
                target = max(h + (mid - (h - reads[pt])) / 2, h + mid - 2 * (h - reads[pt]));
            
            while (pt < m && reads[pt] <= target)
                pt ++;
            
            if (pt == m) break;
        }

        if (pt < m) l = mid + 1;
        else r = mid - 1;
    }

    cout << l;

    return 0;
}