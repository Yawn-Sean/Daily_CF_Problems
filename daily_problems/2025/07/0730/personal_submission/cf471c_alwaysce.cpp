#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n;
    cin >> n;

    i64 ans = 0;
    for (i64 h = 0; ; h++) {
        if (h == 0) {
            if (n % 3 == 2) {
                ans++;
            }
        } else {
            i64 mn = (h + 1) * (h + 2) + h * (h + 1) / 2;
            if (mn > n) {
                break;
            }
            
            i64 diff = n - mn;
            if (diff % 3 == 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
