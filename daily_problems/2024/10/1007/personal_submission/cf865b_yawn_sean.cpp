#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, tot;
    cin >> n >> tot;

    vector<pair<int, int>> v1, v2;
    long long cnt1 = 0, cnt2 = 0, ans = 0;

    while (n --) {
        int s, a, b;
        cin >> s >> a >> b;
        if (a >= b) {
            ans += 1ll * s * a;
            v1.emplace_back(a - b, s);
            cnt1 += s;
        }
        else {
            ans += 1ll * s * b;
            v2.emplace_back(b - a, s);
            cnt2 += s;
        }
    }

    if ((cnt1 + tot - 1) / tot + (cnt2 + tot - 1) / tot == (cnt1 + cnt2 + tot - 1) / tot)
        cout << ans;
    else {
        sort(v1.begin(), v1.end());

        int to_remove1 = cnt1 % tot;
        long long val1 = 0;

        for (auto &[x, cnt]: v1) {
            int c = min(cnt, to_remove1);
            to_remove1 -= c;
            val1 += 1ll * c * x;
        }

        sort(v2.begin(), v2.end());

        int to_remove2 = cnt2 % tot;
        long long val2 = 0;

        for (auto &[x, cnt]: v2) {
            int c = min(cnt, to_remove2);
            to_remove2 -= c;
            val2 += 1ll * c * x;
        }

        cout << ans - min(val1, val2);
    }

    return 0;
}