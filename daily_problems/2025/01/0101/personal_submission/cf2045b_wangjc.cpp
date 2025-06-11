#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n, d, s;
    cin >> n >> d >> s;
    
    n /= s;
    d /= s;
    if (n - 1 <= d) {
        cout << n * s;
        return;
    }
    
    n = min(n, 2 * d);
    for (int i = 2; i <= 1e6; i++) {
        if (n % i == 0 && n - n / i <= d) {
            cout << n * s;
            return;
        }
    }
    cout << (n - 1) * s;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
