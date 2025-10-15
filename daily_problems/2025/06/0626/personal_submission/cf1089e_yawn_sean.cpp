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

    vector<int> cnt(8, 0);
    cnt[0] = 1;
    cnt[7] = 2;
    n -= 2;

    for (int i = 0; i < 8; i ++) {
        int x = min(8 - cnt[i], n);
        n -= x;
        cnt[i] += x;
    }

    int cur = 1;

    for (int i = 0; i < 7; i ++) {
        if (cnt[i]) {
            vector<int> tmp = {cur};
            for (int j = 1; j <= 8; j ++) {
                if (j != cur && tmp.size() < cnt[i]) {
                    tmp.emplace_back(j);
                }
            }
            if (cnt[i] == 8) swap(tmp[6], tmp[7]);
            for (auto &x: tmp) cout << (char)('a' + i) << x << ' ';
            cur = tmp.back();
        }
    }

    vector<int> tmp = {cur};
    for (int j = 1; j <= 8; j ++) {
        if (j != cur && tmp.size() < cnt[7]) {
            tmp.emplace_back(j);
        }
    }
    tmp.back() = 8;
    for (auto &x: tmp) cout << 'h' << x << ' ';

    return 0;
}