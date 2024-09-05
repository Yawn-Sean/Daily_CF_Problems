#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7, inf = 1e9;

void solve(){
    long long n, m, k;
    cin >> n >> m >> k;
    if (k > n+m-2){
        cout << -1 << "\n";
        return;
    }
    long long res = n/(k+1)*m;
    for (long long i = 1, r = 0; i <= n; i = r+1){
        r = n / (n/i);
        if (r-1 > k) break;
        res = max(res, (n/r)*(m/(k-r+2)));
    }
    cout << res << "\n";
}
