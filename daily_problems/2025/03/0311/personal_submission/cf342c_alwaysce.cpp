#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    /*
        每个气球都是半径为r
        的球体。
        帮助秋莎计算她的橱柜里最多可以放多少个气球。
    */

    i64 r, h;
    cin >> r >> h;

    i64 ans = (h / r) * 2;
    h %= r;

    if (4ll * h * h >= 3ll * r * r) {
        ans += 3;
    } else if (2ll * h >= r) {
        ans += 2;
    } else {
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
