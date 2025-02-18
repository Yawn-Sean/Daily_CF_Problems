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

    string a, c;
    int b, d;

    cin >> b >> d >> a >> c;

    int m = c.size();

    vector<int> to_idx(m), cnt(m, 0);
    iota(to_idx.begin(), to_idx.end(), 0);
    
    for (int i = 0; i < m; i ++) {
        for (auto &ch: a) {
            if (ch == c[to_idx[i]]) {
                to_idx[i] ++;
                if (to_idx[i] == m) {
                    to_idx[i] = 0;
                    cnt[i] ++;
                }
            }
        }
    }

    int idx = 0, cur = 0;
    while (b --) {
        cur += cnt[idx];
        idx = to_idx[idx];
    }
    cout << cur / d;

    return 0;
}