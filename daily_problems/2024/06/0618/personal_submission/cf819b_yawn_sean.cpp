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

    vector<long long> diff_b(2 * n + 1), diff_k(2 * n + 1);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        int l = n + x - 1 - i, r = 2 * n - 1 - i;
        diff_k[l] ++, diff_k[r+1] --;
        diff_b[l] -= l, diff_b[r+1] += l;
    }

    for (int i = 0; i < 2 * n; i ++)
        diff_k[i+1] += diff_k[i], diff_b[i+1] += diff_b[i];

    vector<long long> ans(n);
    for (int i = 0; i < 2 * n; i ++)
        ans[i % n] += 1ll * diff_k[i] * i + diff_b[i];

    auto pt = min_element(ans.begin(), ans.end());
    cout << *pt * 2 << ' ' << (pt - ans.begin()) << '\n';

    return 0;
}