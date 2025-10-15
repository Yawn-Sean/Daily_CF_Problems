#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 x, y, m;
    cin >> x >> y >> m;
    /*
        (x,y) -> (x+y,y)
        假设x<y
        x+y>y

        那么
        (x,y) -> (y,x+y)-> (x+y,x+2y) -> (x+2y,2x+3y)->(2x+3y, 3x+5y)
    */

    i64 mn = min(x, y);
    i64 mx = max(x, y);
    if (mx >= m) {
        cout << 0 << endl;
        return 0;
    }

    i64 ans = 0;
    if (mx > 0 && mn + mx <= 0) {
        i64 diff = (mx - mn);
        i64 rep = (diff / mx) + (diff % mx != 0);
        ans += rep;
        mn += mx * rep;
    }
    
    i64 new_mn = min(mn, mx);
    i64 new_mx = max(mn, mx);

    mn = new_mn;
    mx = new_mx;

    while (true) {
        if (mx >= m) {
            break;
        }
        
        if (mn + mx <= 0) {
            cout << -1 << endl;
            return 0;
        }

        i64 nxt = mn + mx;
        if (nxt > mx) {
            mn = mx;
            mx = nxt;
        } else if (nxt > mn) {
            mn = nxt;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
