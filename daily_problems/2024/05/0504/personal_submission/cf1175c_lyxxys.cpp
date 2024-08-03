#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200050, p = 998244353, INF = 2e9;
vector <ll> a(N);
int n, k;

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    ll res = -1, last = 2e9;  //d(k+1) = last
    for (int i = 1; i <= n-k; ++ i)
        if (last > a[i+k] - a[i]){  //如果解法更优，d(k+1)更小
            last = a[i+k]-a[i];  //last >= 上取整((a[i+k]-a[i])/2), res = (a[i+k]+a[i])/2 取到该最小值
            res = (a[i+k]+a[i])/2;
        }

    cout << res << "\n";
}
