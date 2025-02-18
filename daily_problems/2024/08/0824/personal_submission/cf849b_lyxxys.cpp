#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector <int> h(n+1), vis(n+1);
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    
    // 枚举关于点1的所有直线，特判直线只经过点1的情况
    for (int i = 2; i <= n; ++ i){
        int d1 = h[i]-h[1], d2 = i-1;
        int c = 0;
        int d = __gcd(d1, d2);
        d1 /= d, d2 /= d;
        if (d2 < 0) d1 = -d1, d2 = -d2;
        for (ll j = 1, hj = h[1]; j <= n; j += d2, hj += d1){
            if (hj == h[j]) vis[j] = 1, ++ c;
        }
        if (c == n){
            cout << "No\n";
            return;
        }
        int p = 1;
        while (vis[p]) ++ p;
        for (ll j = p, hj = h[p]; j <= n; j += d2, hj += d1){
            if (hj == h[j]) vis[j] = 1, ++ c;
        }
        if (c == n){
            cout << "Yes\n";
            return;
        }
        for (int k = 1; k <= n; ++ k) vis[k] = 0;
    }
    int d1 = h[3]-h[2];
    int c = 0;
    for (ll j = 2, hj = h[2]; j <= n; j += 1, hj += d1){
        if (hj == h[j]) ++ c;
    }
    if (c == n-1){
        cout << "Yes\n";
        return;
    }

    cout << "No\n";
}
