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

    int t, mod = 1e9 + 7;
    cin >> t;

    while (t --) {
        int x;
        string s;
        cin >> x >> s;

        int k = s.size(), npt = min(k, x);
        vector<int> tmp(x);

        for (int i = 0; i < npt; i ++)
            tmp[i] = s[i] - '0';
        
        int cur_len = k;
        for (int pt = 0; pt < x; pt ++) {
            if (tmp[pt] == 0) break;

            cur_len += (cur_len - pt - 1) * (tmp[pt] - 1) % mod;
            if (cur_len >= mod) cur_len -= mod;

            int p = pt + 1, e = npt, c = 1;
            while (c < tmp[pt] && npt < x) {
                tmp[npt] = tmp[p];
                npt ++, p ++;
                if (p == e)
                    p = pt + 1, c ++;
            }
        }
        cout << cur_len << '\n';
    }

    return 0;
}