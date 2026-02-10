#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;
    return x;
}

int n, p1 = -1, p2 = -1;
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x = ask(i, i);
        if (x == n) {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }
    if (p2 == -1) cout << "! " << 0 << endl;
    else {
        for (int i = 0; i < n; ++i) {
            if (i != p1) {
                int x = ask(p1, i), ans;
                if (x == n) ans = p2 - p1;
                else ans = (p1 - p2 + n) % n;
                cout << "! " << ans << endl;
                break;
            }
        }
    }
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
} 
