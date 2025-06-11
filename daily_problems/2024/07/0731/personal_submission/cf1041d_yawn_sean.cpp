#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, h;
    cin >> n >> h;

    vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i ++)
        cin >> ls[i] >> rs[i];
    
    int l = 0, r = 0, cur = h, res = 0, ans = 0;

    while (l < n) {
        while (r < n - 1 && ls[r+1] - rs[r] < cur) {
            res += rs[r] - ls[r];
            cur -= ls[r+1] - rs[r];
            r ++;
        }
        ans = max(ans, res + rs[r] - ls[r] + h);
        res -= rs[l] - ls[l];
        l ++;
        if (l < n)
            cur += ls[l] - rs[l-1];
    }
    cout << ans;

    return 0;
}