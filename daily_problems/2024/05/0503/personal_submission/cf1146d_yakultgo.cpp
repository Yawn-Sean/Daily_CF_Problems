#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, a, b, i, ans, lst;
bool v[1000005];
void dfs(int x) {
    if (v[x]) return;
    lst++;
    v[x] = 1;
    if (x + a <= i) dfs(x + a);
    if (x - b >= 0) dfs(x - b);
}
signed main() {
    cin >> m >> a >> b;
    int k = a + b - 1;
    i = 0;
    dfs(0);
    ans += lst;
    for (i = 1; i <= min(k, m); i++) {
        if (i - a >= 0 && v[i - a]) {
            dfs(i);
        }
        ans += lst;
    }
    if (m < k) {
        cout << ans << endl;
        return 0;
    }
    int c = gcd(a, b);
    for (i = k + 1; i <= m; i++) {
        if (i % c == 0) break;
        ans += i / c + 1;
    }
    int d = m / c * c - 1;
    ans += (d - i + 1) + ((m / c - 1) + (i / c)) * (m / c - 1 - (i / c) + 1) / 2 * c;
    for (i = d + 1; i <= m; i++) {
        ans += i / c + 1;
    }
    cout << ans << endl;
    return 0;
}