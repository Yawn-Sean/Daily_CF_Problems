#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll p = n * 2 * ((m - 1) / 2);
    if (k <= n) cout << k << endl;
    else if (k >= p + n) cout << n - (k - n - p) << endl;
    else {
        if ((n & 1) ^ (k & 1)) cout << n - 1 << endl;
        else cout << n << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
