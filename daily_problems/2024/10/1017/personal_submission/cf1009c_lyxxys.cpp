#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    long long c2 = 1ll*n*(n-1)/2, c1 = 0;
    for (int i = 1, mid = (n+1)/2; i <= n; ++ i){
        c1 += abs(mid-i);
    }

    assert(c2 >= c1);
    long long res = 0;
    for (int i = 0; i < m; ++ i){
        int x, d;
        cin >> x >> d;
        res += n*x;
        if (d >= 0){
            res += c2 * d;
        } else {
            res += c1 * d;
        }
    }

    cout << fixed << setprecision(10) << (1.0*res/n) << "\n";
}
