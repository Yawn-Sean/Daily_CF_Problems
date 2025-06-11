#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(1 << 14);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    if (k == 0) {
        long long ans = 0;
        for (int i = 0; i < (1 << 14); i ++) {
            ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans;
    }
    else {
        vector<int> vals;
        for (int i = 0; i < (1 << 14); i ++) {
            if (__builtin_popcount(i) == k) vals.emplace_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < (1 << 14); i ++) {
            for (auto v: vals) ans += 1ll * cnt[i] * cnt[i ^ v];
        }
        cout << ans / 2;
    }

    return 0;
}