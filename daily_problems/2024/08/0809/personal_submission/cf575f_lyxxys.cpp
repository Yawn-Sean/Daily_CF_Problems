#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, x;
    cin >> n >> x;
    int l = x, r = x;

    ll res = 0;
    while (n--){
        int lt, rt;
        cin >> lt >> rt;
        if (l > rt){
            res += l-rt;
            r = l;
            l = rt;
        } else if (r < lt){
            res += lt-r;
            l = r;
            r = lt;
        } else {
            l = max(l, lt), r = min(r, rt);
        }
    }

    cout << res << "\n";
}
