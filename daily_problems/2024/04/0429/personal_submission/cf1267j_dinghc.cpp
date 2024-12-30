#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> freq;
        for (int i = 0, c; i < n; i++) {
            cin >> c;
            freq[c]++;
        }
        int mn = n;
        for (auto&[_, cnt] : freq) {
            mn = min(mn, cnt);
        }
        int ans = n;
        for (int s = 2; s <= mn + 1; s++) {
            int tot = 0;
            for (auto&[_, cnt] : freq) {
                // (s - 1) * f <= cnt and s * f >= cnt
                int f = (cnt + s - 1) / s;
                if (s * f - f > cnt) {
                    tot = 0;
                    break;
                }
                tot += f;
            }
            if (tot) ans = min(ans, tot);
        }
        cout << ans << "\n";
    }
    return 0;
}

