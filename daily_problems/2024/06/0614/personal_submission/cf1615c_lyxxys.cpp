#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18, mod = 998244353, N = 20050;

void solve(){
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    a = " " + a, b = " " + b;

    int ct1 = 0, ct2 = 0;
    int res = 1e9;
    for (int i = 1; i <= n; ++ i)
        if (a[i] == '1') ++ ct1;
    for (int i = 1; i <= n; ++ i)
        if (b[i] == '1') ++ ct2;
    //考虑目标状态的正状态
    if (ct1 == ct2){
        int ct = 0;
        for (int i = 1; i <= n; ++ i)
            if (a[i] == '1' && b[i] == '0') ++ ct;
        res = min(res, 2*ct);
    }
    //考虑目标状态的反状态
    if (ct2 > 0){
        int cnt = (n+1-ct2);
        if (cnt == ct1){
            int pos = n+1;
            for (int i = 1; i <= n; ++ i)
                if (a[i] == '1' && a[i] == b[i]){
                    pos = i;
                    break;
                }
            if (pos != n+1) {
                for (int i = 1; i <= n; ++i)
                    if (i != pos) b[i] = (b[i] == '1' ? '0' : '1');
                int ct = 0;
                for (int i = 1; i <= n; ++i)
                    if (a[i] == '1' && b[i] == '0') ++ct;
                res = min(res, 2 * ct + 1);
            } else res = min(res, 2*ct2+1);
        }
    }

    if (res == 1e9) return cout << -1 << "\n", void();
    cout << res << "\n";
}
