#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (1ll * (k + 1) * k / 2 > n)
        cout << "NO";
    else {
        vector<int> ans(k);
        iota(ans.begin(), ans.end(), 1);
        n -= k * (k + 1) / 2;

        for (int i = 0; i < k; i ++)
            ans[i] += n / k;
        
        n %= k;

        for (int i = k - 1; i > 0 && ans[i-1] != 1 && n > 0; i --) {
            ans[i] ++, n --;
        }
        ans[k - 1] += n;

        for (int i = 0; i < k - 1; i ++)
            if (ans[i] * 2 < ans[i + 1]) {
                cout << "NO";
                return 0;
            }
        
        cout << "YES\n";
        for (auto &x: ans) cout << x << ' ';
    }

    return 0;
}