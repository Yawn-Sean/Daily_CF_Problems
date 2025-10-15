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

    vector<int> cnt(n, 0), max_flg(n, 0);

    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;

        if (b != n) return cout << "NO", 0;
        cnt[a] ++, max_flg[a] = 1;
    }

    vector<int> chain;
    int cur = 1;

    for (int i = 1; i < n; i ++) {
        if (cnt[i]) {
            cnt[i] --;
            chain.emplace_back(i);

            while (cnt[i]) {
                while (max_flg[cur]) cur ++;
                if (cur > i) return cout << "NO", 0;
                chain.emplace_back(cur);
                cur ++, cnt[i] --;
            }
        }
    }

    chain.emplace_back(n);

    cout << "YES\n";
    for (int i = 1; i < n; i ++)
        cout << chain[i - 1] << ' ' << chain[i] << '\n';

    return 0;
}