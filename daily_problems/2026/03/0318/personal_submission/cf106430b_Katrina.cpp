#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cerr << #a << " = "; for (auto x : a) cerr << x << " "; cerr << endl;



void solve() {  
    int x, y; cin >> x >> y;
    int ans = 0;
    if (x == y) cout << "0\n";
    else if (x < y) {
        while (x < y) {
            x *= 2;
            ans++;
        }
        cout << ans << "\n";
    }
    else {
        if (y < 3) cout << "-1\n";
        else {
            while (x > y) {
                x = 2 * x / 3 + 1;
                ans++;
            }
            cout << ans << "\n";

        }
    }
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
   
    int T = 1;
    cin >> T;  
    while (T--) solve();    
    return 0;
}  
