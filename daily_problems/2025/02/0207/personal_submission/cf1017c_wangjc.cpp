#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    int cur = INT_MAX;
    int x = 1;
    int ans = 0;
    while (x <= n) {
        int now = 0;
        if (n % x == 0) now = n / x + x;
        else now = x + n / x + 1;
        if (now < cur) {
            cur = now;
            ans = x;
        }
        x++;
    }
    x = ans;
    for (int i = n / x - 1; i >= 0; i--) {
        for (int j = 1 + n % x; j <= x + n % x; j++) {
            cout << i * x + j << " ";
        }
    }
    for (int i = 1; i <= n % x; i++) {
        cout << i << " ";
    }
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
