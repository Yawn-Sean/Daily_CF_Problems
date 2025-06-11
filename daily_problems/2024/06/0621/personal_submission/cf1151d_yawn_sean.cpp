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

    vector<int> tmp(n);
    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        tmp[i] = a - b;
        ans += 1ll * b * n - a;
    }
    
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < n; i ++)
        ans += 1ll * tmp[i] * (n - i);

    cout << ans << '\n';

    return 0;
}