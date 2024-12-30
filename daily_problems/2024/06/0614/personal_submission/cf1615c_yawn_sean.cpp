#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;

        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i ++)
            c1 += (s1[i] == '1'), c2 += (s2[i] == '1');
        
        int ans = n + 5;
        if (c1 == c2) {
            int res = 0;
            for (int i = 0; i < n; i ++)
                res += (s1[i] != s2[i]);
            ans = min(ans, res);
        }
        if (n - c1 + 1 == c2) {
            int res = 0, f = 0;
            for (int i = 0; i < n; i ++) {
                if (s1[i] == s2[i])
                    res += 1, f |= (s1[i] == '1');
            }
            ans = min(ans, res + 2 - f * 2);
        }
        cout << (ans < n + 5 ? ans : -1) << '\n';
    }

    return 0;
}