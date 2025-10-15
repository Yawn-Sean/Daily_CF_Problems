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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> nums1(n);
    vector<int> nums2(m);

    long long val1 = 0, val2 = 0;
    for (auto &v: nums1) cin >> v, val1 += v;
    for (auto &v: nums2) cin >> v, val2 += v;
    
    int bound = 2e5;
    vector<bool> v1(bound * 2 + 1, 0);
    vector<bool> v2(bound * 2 + 1, 0);

    for (auto &v: nums1) {
        long long x = val1 - v;
        if (x >= -bound && x <= bound)
            v1[x + bound] = 1;
    }

    for (auto &v: nums2) {
        long long x = val2 - v;
        if (x >= -bound && x <= bound)
            v2[x + bound] = 1;
    }

    while (q --) {
        int x;
        cin >> x;

        bool flg = false;

        for (int i = 1; i <= 500; i ++) {
            if (x % i == 0) {
                int j = x / i;
                
                if (v1[i + bound] and v2[j + bound]) flg = true;
                if (v2[i + bound] and v1[j + bound]) flg = true;
                if (v1[-i + bound] and v2[-j + bound]) flg = true;
                if (v2[-i + bound] and v1[-j + bound]) flg = true;
                if (flg) break;
            }
        }

        cout << (flg ? "YES" : "NO") << '\n';
    }

    return 0;
}