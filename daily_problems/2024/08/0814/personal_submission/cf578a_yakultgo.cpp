#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    if (x < y)
        cout << -1;
    else {
        double ans = 1e15;
        int tmp;
        tmp = x - y;
        if (tmp >= 2 * y) {
            int k = tmp / (2 * y);
            ans = min(ans, 1.0 * tmp / 2 / k);
        }
        tmp = x + y;
        if (tmp >= 2 * y) {
            int k = tmp / (2 * y);
            ans = min(ans, 1.0 * tmp / 2 / k);
        }
        cout << setprecision(12) << ans;
    }

    return 0;
}