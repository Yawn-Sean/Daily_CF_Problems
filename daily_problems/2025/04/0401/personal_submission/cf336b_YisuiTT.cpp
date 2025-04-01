#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
void solve(){
    i64 m, r;
    cin >> m >> r;
    double ans = 0.0;
    for(i64 i = 1; i <= m; i++){
        ans += 2 * r;
        if(i - 1 >= 1)ans += 2 * r + sqrt(2) * r;
        i64 pre = max(i - 2, 0LL);
        ans += pre * (pre - 1) * r + pre * (2 * r + sqrt(2) * r * 2);
        if(i + 1 <= m)ans += 2 * r + sqrt(2) * r;
        i64 sub = m - min(i + 1, m);
        ans += sub * (sub - 1) * r + sub * (2 * r + sqrt(2) * r * 2);
    }
    cout << fixed << setprecision(8) << ans / (m * m) << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
