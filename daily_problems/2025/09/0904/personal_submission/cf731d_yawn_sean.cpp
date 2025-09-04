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

    int n, c;
    cin >> n >> c;

    vector<int> diff(c + 1, 0);

    int k1 = 0;
    vector<int> v1;

    for (int i = 0; i < n; i ++) {
        int k2;
        cin >> k2;

        vector<int> v2(k2);
        for (auto &x: v2) cin >> x;

        bool flg = false;
        for (int i = 0; i < min(k1, k2); i ++) {
            if (v1[i] != v2[i]) {
                if (v1[i] < v2[i]) {
                    diff[0] ++, diff[c - v2[i] + 1] --;
                    diff[c - v1[i] + 1] ++, diff[c] --;
                }
                else diff[c - v1[i] + 1] ++, diff[c - v2[i] + 1] --;
                flg = true;
                break;
            }
        }

        if (!flg) {
            if (k1 > k2) return cout << -1, 0;
            else diff[0] ++, diff[c] --;
        }

        k1 = k2;
        v1 = v2;
    }

    for (int i = 1; i <= c; i ++)
        diff[i] += diff[i - 1];
    
    for (int i = 0; i <= c; i ++)
        if (diff[i] == n) return cout << i, 0;
    
    cout << -1;

    return 0;
}