#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int f(int x, int n) {
    while (n--) {
        if (!x) return x;
        x /= 2;
    }
    return x;
}

int g(int x, int n) {
    while (n--) {
        if (x <= 1) return x;
        x = (x + 1) / 2;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    i64 x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<i64> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
    }

    i64 ans = 1e18, tmp = 0;
    // r1圆为空
    for (int j = 0; j < n; j++) {
        i64 dj2 = (x2 - xs[j]) * (x2 - xs[j]) + (y2 - ys[j]) * (y2 - ys[j]);
        tmp = max(tmp, dj2);
    }
    ans = min(ans, tmp);

    // b1: 存在r1圆 的边界点为b1
    for (int b1 = 0; b1 < n; b1++) {
        i64 mx1 = (x1 - xs[b1]) * (x1 - xs[b1]) + (y1 - ys[b1]) * (y1 - ys[b1]);
        i64 mx2 = 0;
        for (int j = 0; j < n; j++) {
            i64 dj1 = (x1 - xs[j]) * (x1 - xs[j]) + (y1 - ys[j]) * (y1 - ys[j]);
            if (dj1 > mx1) {
                i64 dj2 = (x2 - xs[j]) * (x2 - xs[j]) + (y2 - ys[j]) * (y2 - ys[j]);
                mx2 = max(mx2, dj2);
            } 
        }
        ans = min(ans, mx1 + mx2);
    }

    cout << ans << "\n";
    return 0;
}
