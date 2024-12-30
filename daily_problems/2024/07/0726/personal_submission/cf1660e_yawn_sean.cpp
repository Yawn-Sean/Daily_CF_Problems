#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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
        cin >> n;

        vector<int> cnt(n);
        int ans = n;

        for (int i = 0; i < n; i ++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j ++)
                if (s[j] - '0')
                    cnt[(i + n - j) % n] ++, ans ++;
        }
        cout << ans - *max_element(cnt.begin(), cnt.end()) * 2 << '\n';
    }

    return 0;
}