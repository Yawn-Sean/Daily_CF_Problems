#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {
    int a, b, m; cin >> a >> b >> m;
    int bit = 31 - __builtin_clz(m);
    cout << bit;
	cout << ((b + 1) >> bit) - (a >> bit) << '\n';
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    cin >> T;  
    while (T--) solve();    
    return 0;
} 
