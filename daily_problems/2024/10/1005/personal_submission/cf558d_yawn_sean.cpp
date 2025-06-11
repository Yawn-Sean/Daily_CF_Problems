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

    int h, q;
    cin >> h >> q;

    map<long long, int> mp;
    mp[1ll << h - 1] = 0;
    mp[1ll << h] = 0;

    for (int i = 0; i < q; i ++) {
        int idx, ans;
        long long l, r;
        cin >> idx >> l >> r >> ans;
        r ++;
        l <<= h - idx;
        r <<= h - idx;

        if (ans) mp[l] ++, mp[r] --;
        else mp[1ll << h - 1] ++, mp[l] --, mp[r] ++, mp[1ll << h] --;
    }

    int cur = 0;
    long long start = 0, cnt = 0, last = 1ll << h  - 1;

    for (auto &[k, v]: mp) {
        if (cur == q) {
            cnt += k - last;
            start = last;
        }
        cur += v;
        last = k;
    }

    if (cnt == 0) cout << "Game cheated!";
    else if (cnt == 1) cout << start;
    else cout << "Data not sufficient!";

    return 0;
}