#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){            
    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;

    int a = ra-la+1;
    int b = rb-lb+1;
    int d = __gcd(ta, tb);
    int x = ((la-lb)%d + d)%d;
    // bob左侧 离 alice 左侧 距离为 x, 枚举相差最小的两种情况
    int res = max(0, min(x+a-1,b-1)-x + 1);
    res = max(res, min(x-d+a-1, b-1) + 1);
    cout << res << "\n";
}
