#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long x;
    cin >> x;

    vector<pair<long long, long long>> prs;

    for (long long mi = 1; mi <= 2000000; mi ++) {
        long long a = mi * (mi + 1) * (2 * mi + 1) / 6;
        long long b = mi * (mi + 1) / 2;
        if (x >= a && (x - a) % b == 0) {
            long long w = mi, h = mi + (x - a) / b;
            prs.emplace_back(w, h);
            if (w != h) prs.emplace_back(h, w);
        }
    }

    sort(prs.begin(), prs.end());
    cout << prs.size() << '\n';
    for (auto &[x, y]: prs)
        cout << x << ' ' << y << '\n';

    return 0;
}