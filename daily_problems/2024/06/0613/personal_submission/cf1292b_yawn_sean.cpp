#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long x0, y0, bx, by, xs, ys, t;
    int ax, ay;

    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;

    long long x = x0, y = y0;
    vector<long long> px, py;

    while (x + y - xs - ys <= t) {
        px.push_back(x);
        py.push_back(y);
        x = x * ax + bx;
        y = y * ay + by;
    }

    int ans = 0, n = px.size();

    for (int i = 0; i < n; i ++) 
        for (int j = 0; j <= i; j ++)
            for (int k = i; k < n; k ++)
                if (abs(xs - px[i]) + abs(ys - py[i]) + px[k] - px[j] + py[k] - py[j] + min(px[k] - px[i] + py[k] - py[i], px[i] - px[j] + py[i] - py[j]) <= t)
                    ans = max(ans, k - j + 1);
    
    cout << ans << '\n';

    return 0;
}