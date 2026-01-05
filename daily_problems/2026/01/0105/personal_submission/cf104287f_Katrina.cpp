#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << c - gcd(c, lcm(a, b)) << "\n";
}


signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;  
    while (T--) solve();    
    return 0;
} 
