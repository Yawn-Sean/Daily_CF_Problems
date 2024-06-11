#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, d;
    cin >> n >> d;
    int l = 0, r = 0, ans = 0;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (!x) {
            l = max(l, 0);
            if (r < 0) 
                r = d, ans ++;
        }
        else {
            l += x;
            r += x;
            if (l > d) {
                cout << -1 << '\n';
                return 0;
            }
            r = min(r, d);
        }
    }
    cout << ans << '\n';
    return 0;
}