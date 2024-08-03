#include <iostream>
#include <string>
using namespace std;
#define int long long

void yrlpSolve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    int ans = 0, x = 0, y = 0, f = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i] and f) {
            ans++;
            continue;
        }
        f = 0;
        if (x == 0 and y == 0) {
            x = 1, y = 1;
        } else {
            x *= 2, y *= 2;
        }
        if (s[i] == 'b') x -= 1;
        if (t[i] == 'a') y -= 1;
        if (x + y < k) {
            ans += x + y;
        } else {
            ans += k * (n - i);
            break;
        }
    }
    cout << ans << endl;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
