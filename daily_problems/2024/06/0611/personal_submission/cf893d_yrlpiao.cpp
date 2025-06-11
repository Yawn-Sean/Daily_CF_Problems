#include <iostream>
using namespace std;

int arr[1 << 20] {}, sum[1 << 20] {}, mx[1 << 20] {};
int yrlpSolve() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    mx[n + 1] = -1e9;
    for (int i = n; i >= 1; i--) {
        mx[i] = max(mx[i + 1], sum[i]);
    }
    int c = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != 0) {
            c += arr[i];
            if (c > d) return cout << -1, 0;
        } else {
            if (c < 0) {
                int x = mx[i] - sum[i];
                if (x > d) return cout << -1, 0;
                c = min(d, d - x);
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
