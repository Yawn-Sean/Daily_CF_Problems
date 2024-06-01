#include <bits/stdc++.h>
using namespace std;
const int N = 5050, mod = 998244353, inf = 1e9;

void solve(){
    int n, x, minf = inf, maxf = -inf;
    cin >> n >> x;
    vector <int> a(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        minf = min(minf, a[i]), maxf = max(maxf, a[i]);
    }

    int res = 0;
    for (int i = 1; i < n; ++ i) res += abs(a[i+1]-a[i]);
    if (minf > 1){
        int ans1 = min(a[1]-1, a[n]-1);
        for (int i = 1; i < n; ++ i) ans1 = min(ans1, a[i]+a[i+1]-2-abs(a[i]-a[i+1]));
        res += ans1;
    }
    if (x > maxf){
        int ans2 = min(x-a[1], x-a[n]);
        for (int i = 1; i < n; ++ i) ans2 = min(ans2, 2*x-a[i]-a[i+1]-abs(a[i]-a[i+1]));
        res += ans2;
    }
    cout << res << "\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
