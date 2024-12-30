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

    vector<int> tmp = {1, 2, 3, 5};

    cout << k * (6 * n - 1) << '\n';
    for (int i = 0; i < n; i ++) {
        for (auto &x: tmp) cout << (6 * i + x) * k << ' ';
        cout << '\n';
    }

    return 0;
}