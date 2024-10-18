#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<pair<long long, long long>> tmp;

    for (int i = 0; i < n; i ++) {
        int k, b;
        cin >> k >> b;
        tmp.emplace_back(1ll * k * x1 + b, 1ll * k * x2 + b);
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 1; i < n; i ++) {
        if (tmp[i].second < tmp[i-1].second)
            return cout << "YES", 0;
    }
    cout << "NO";

    return 0;
}