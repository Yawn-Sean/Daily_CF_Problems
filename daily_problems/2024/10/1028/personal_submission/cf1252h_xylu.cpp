#include <bits/stdc++.h>
using namespace std;

void solveH() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n * 2);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i+n][0] = a[i][1];
        a[i+n][1] = a[i][0];
        a[i][2] = a[i+n][2] = i;
        ans = max(ans, 1LL * a[i][0] * a[i][1]);
    }
    sort(a.begin(), a.end());
    int mxy = 0, mxi = -1, mxy2 = 0;
    for (int i = 2*n-1; i >= 0; i--) {
        if (mxi == a[i][2]) {
            ans = max(ans, 2LL * a[i][0] * min(a[i][1], mxy2));
        } else {
            ans = max(ans, 2LL * a[i][0] * min(a[i][1], mxy));
        }
        if (a[i][1] > mxy) {
            mxy2 = mxy;
            mxy = a[i][1];
            mxi = a[i][2];
        } else if (a[i][1] > mxy2 && a[i][2] != mxi) {
            mxy2 = a[i][1];
        }
    }
    cout << ans / 2 << '.' << (ans & 1 ? 5 : 0) << '\n';
}

int main() {
    solveH();
    return 0;
}
