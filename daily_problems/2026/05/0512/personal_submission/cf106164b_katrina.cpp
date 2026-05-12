#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;



void solve() {  
    int n, m; cin >> n >> m;
    if (n == 2) {
        if (m & 1) cout << "2 1\n";
        else cout << "1 2\n";
    }
    else {
        m = min(n, m);
        for (int i = 0; i < m; i ++) cout << n - i << ' ';
        for (int i = 1; i <= n - m; i ++) cout << i << ' ';
        cout << '\n';
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


