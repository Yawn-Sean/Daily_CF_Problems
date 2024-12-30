#include <iostream>
using namespace std;
#define int long long 

int b[1 << 20] {}, q[1 << 20] {}, d[1 << 20] {};
void put(int val, int l, int r, int c) {
    d[l] += val - c;
    d[r + 1] -= val - c;
    b[l] += c; b[r + 1] -= c;
    q[r + 1] -= (r - l + 1) * c;
}
void yrlpSolve() {
    int n; cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == i) {
            put(1, 1, i - 1, 1);
            put(n - x, i, n - 1, -1);
        } else if (x < i) {
            put(i - x, 0, i - x, -1);
            put(1, i - x + 1, i - 1, 1);
            put(n - x, i, n - 1, -1);
        } else {
            put(x - i, 0, i - 1, 1);
            put(n - x, i, i + n - x, -1);
            put(1, i + n - x + 1, n - 1, 1);
        }
    }
    for (int i = 1; i < n; i++) b[i] += b[i - 1], d[i] += d[i - 1];
    for (int i = 1; i < n; i++) b[i] += b[i - 1] + q[i];
    for (int i = 0; i < n; i++) b[i] += d[i];
   
    int ans = 1e18, c = 0;
    for (int i = 0; i < n; i++) {
        if (ans > b[i]) {
            ans = b[i];
            c = i;
        }
    }
    cout << ans << " " << (n - c) % n;
    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
