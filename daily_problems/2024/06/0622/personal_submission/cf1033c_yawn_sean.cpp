#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> perm(n);
    for (auto &x: perm) cin >> x;

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i ++)
        pos[perm[i]] = i;
    
    vector<int> dp(n);

    for (int i = n; i > 0; i --)
        for (int j = pos[i] % i; j < n; j += i)
            if (perm[j] > i && !dp[j])
                dp[pos[i]] = 1;
    
    for (auto &x: dp) cout << "BA"[x];

    return 0;
}