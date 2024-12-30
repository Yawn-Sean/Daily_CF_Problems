#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 9e18, mod = 998244353, N = 200050;

void solve(){
    int n, k;
    cin >> n >> k;

    vector <int> a(n+1), nxt(n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    // 缩区间内数字为1的 段，保证最多隔1次乘以 大于1的整数

    for (int i = n, last = 0; i >= 1; -- i){
        if (a[i] != 1) last = 0;
        if (!last && a[i] == 1) last = i;
        if (last && a[i] == 1) nxt[i] = last;
    }
    int res = 0;

    for (int i = 1; i <= n; ++ i){
        __int128 x = 1;
        ll deno = 0;
        for (int j = i; j <= n; ++ j){
            if (x > 2e18) break;
            if (nxt[j]) {
                if (k*deno < x){
                    __int128 to = x/k - deno;
                    if (to > 0 && j+to-1 <= nxt[j]) deno += to, j = j+to-1;
                    else deno += (nxt[j] - j + 1), j = nxt[j];
                }
                else deno += (nxt[j] - j + 1), j = nxt[j];
            }
            else {
                deno += a[j], x = x*a[j];
            }
            if (x%deno==0 && x/deno==k) ++ res;
        }
    }
    cout << res << "\n";
}
