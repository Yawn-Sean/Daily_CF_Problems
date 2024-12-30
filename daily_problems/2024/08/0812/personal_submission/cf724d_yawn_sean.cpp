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

    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < 26; i ++) {
        int cur = -1;
        bool flg = true;
        for (int idx = 0; idx < n; idx ++) {
            if (s[idx] - 'a' <= i) cur = idx;
            else if (idx - cur >= m) flg = false;
        }
        if (flg) {
            vector<int> cnt(26);
            int cur = -1, pos = -1;
            for (int idx = 0; idx < n; idx ++) {
                if (s[idx] - 'a' < i) {
                    cur = idx;
                    cnt[s[idx] - 'a'] ++;
                }
                else if (s[idx] - 'a' == i) {
                    pos = idx;
                }
                if (idx - cur == m) {
                    cnt[i] ++;
                    cur = pos;
                }
            }
            for (int c = 0; c < 26; c ++) {
                for (int j = 0; j < cnt[c]; j ++) {
                    cout << (char) ('a' + c);
                }
            }
            return 0;
        }
    }

    return 0;
}