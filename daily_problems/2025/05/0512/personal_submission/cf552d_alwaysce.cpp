#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i64 n;
    cin >> n;
    
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
    }

    int ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++) {
        map<pair<int,int>, int> cnt;
        for (int j = 0; j < i; j++) {
            int dx = xs[j] - xs[i];
            int dy = ys[j] - ys[i];
            
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            ans -= cnt[{dx, dy}];
            cnt[{dx, dy}] += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
