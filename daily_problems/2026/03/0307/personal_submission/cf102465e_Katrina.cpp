#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {  
    int n; cin >> n;
    int sum = 0, val = 0;
    vector<string> s(n); vector<int> l(n), add(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> l[i];
        if (l[i] == 0) add[i] = 49;
        else if (l[i] == 100) l[i] = 9950, add[i] = 50;
        else l[i] = l[i] * 100 - 50, add[i] = 99;
        sum += l[i], val += add[i];
    }
    if (sum > 10000 || sum + val < 10000) cout << "IMPOSSIBLE\n";
    else {
        int d = 10000 - sum;
        for (int i = 0; i < n; ++i) {
            int mi = l[i] + max(0, d - (val - add[i]));
            int mx = l[i] + min(add[i], d);
            cout << s[i];
            cout << ' ' << mi / 100 << (mi % 100 < 10 ? ".0" : ".") << mi % 100; 
			cout << ' ' << mx / 100 << (mx % 100 < 10 ? ".0" : ".") << mx % 100;
            cout << "\n";
        }
    }
    
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
  
    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
}   
