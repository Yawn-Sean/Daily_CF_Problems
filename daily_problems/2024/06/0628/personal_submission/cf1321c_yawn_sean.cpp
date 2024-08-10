#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    while (true) {
        int idx = -1;
        for (int i = 0; i < n; i ++)
            if (((i && s[i] - s[i-1] == 1) || (i < n - 1 && s[i] - s[i+1] == 1)) && (idx == -1 || s[i] > s[idx]))
                idx = i;
        if (idx == -1) break;
        s = s.substr(0, idx) + s.substr(idx + 1, n - idx - 1);
        n --, ans ++;
    }
    cout << ans;

    return 0;
}