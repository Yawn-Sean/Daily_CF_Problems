#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define erp(i, a, b) for (int i = a; i >= b; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

const int mod = 1000000007, mod0 = 998244353;

i64 get2(i64 n) {
    return (n + 1) * n / 2;
}

i64 get1(i64 n) {
    return n * n;
}

i64 get0(i64 n) {
    return 2 * n * n + 2 * n + 1;
}

bool check(i64 t, i64 x, i64 y, i64 n, i64 c) {
    i64 cnt = get0(t);
    if (y + t > n)
        cnt -= get1(y + t - n);
    if (y - t < 1)
        cnt -= get1(t - y + 1);
    if (x + t > n)
        cnt -= get1(x + t - n);
    if (x - t < 1)
        cnt -= get1(t - x + 1);

    if ((x - 1) + (y - 1) < t)
        cnt += get2(t - (x + y - 2) - 1);
    if ((n - x) + (n - y) < t)
        cnt += get2(t - (n - x) - (n - y) - 1);
    if ((x - 1) + (n - y) < t)
        cnt += get2(t - (x - 1) - (n - y) - 1);
    if ((n - x) + (y - 1) < t)
        cnt += get2(t - (n - x) - (y - 1) - 1);
    return cnt >= c;
}

void solve() {
    i64 n, x, y, c;
    cin >> n >> x >> y >> c;
    i64 l = 0, r = 2 * n;
    while (l < r) {
        i64 mid = (l + r) / 2;
        if (check(mid, x, y, n, c))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
