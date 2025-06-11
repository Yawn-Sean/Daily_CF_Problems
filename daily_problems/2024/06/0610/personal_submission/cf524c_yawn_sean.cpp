#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> mp;

    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a;
        for (int j = 0; j <= k; j ++)
            mp[a * j] = j;
    }

    int q;
    cin >> q;

    while (q --) {
        int x, ans = k + 1;;
        cin >> x;
        for (auto &[k, v]: mp) {
            if (mp.find(x - k) != mp.end())
                ans = min(ans, mp[x-k] + v);
        }
        cout << (ans > k ? -1 : ans) << '\n';
    }

    return 0;
}