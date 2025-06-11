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

    map<char, int> mp;
    mp['R'] = -2;
    mp['G'] = -1;
    mp['B'] = 0;

    while (t --) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ans = n;

        for (int i = 0; i < 3; i ++) {
            int cnt = 0;
            for (int j = 0; j < k; j ++)
                if ((j - mp[s[j]]) % 3 != i) cnt ++;
            ans = min(ans, cnt);
            for (int j = k; j < n; j ++) {
                if ((j - mp[s[j]]) % 3 != i) cnt ++;
                if ((j - k - mp[s[j-k]]) % 3 != i) cnt --;
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}