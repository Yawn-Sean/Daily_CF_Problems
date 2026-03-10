#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {  
    int n, m, k; cin >> n >> m >> k;
    if (n & 1) {
        if (m & 1) cout << "Munir\n";
        else {
            if (k > 1) cout << "Munir\n";
            else cout << "Matthew\n";
        }
    }
    else {
        if (m & 1) {
            if (k > 1) cout << "Munir\n";
            else cout << "Matthew\n";
        }
        else {
            if (k >= 4) cout << "Munir\n";
            else cout << "Matthew\n";
        }
    }
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
  
    int T = 1;
    cin >> T;  
    while (T--) solve();    
    return 0;
}   
