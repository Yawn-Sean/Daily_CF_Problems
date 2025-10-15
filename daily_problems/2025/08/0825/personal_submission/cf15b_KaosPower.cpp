//  B. Laser

#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        int a = x1 + n - x2, b = y1 + m - y2;
        cout << 1ll * n * m - 2ll * a * b + 1ll * max(0, 2 * a - n) * max(0, 2 * b - m) << '\n';
    }

    return 0;
}
