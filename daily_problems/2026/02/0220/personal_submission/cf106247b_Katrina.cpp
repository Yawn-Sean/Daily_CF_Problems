#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {
    int n; cin >> n;
    if (n < 3) {
        if (n == 1) {
            cout << "1\n1\n";
        }
        else cout << "-1\n";
        return;
    }
    vector<int> a(n + 1);
    int sum = 3;
    a[1] = 1, a[2] = 2;
    for (int i = 3; i <= n; ++i) {
        a[i] = sum;
        sum += a[i];
    }
    cout << sum << "\n";
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
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
