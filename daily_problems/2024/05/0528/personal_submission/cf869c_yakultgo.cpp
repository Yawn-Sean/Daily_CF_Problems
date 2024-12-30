#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    comb.init(5000);
    int a, b, c;
    cin >> a >> b >> c;
    int ab = min(a, b), bc = min(b, c), ac = min(a, c);
    Z ans = 1;
    Z t1 = 0, t2 = 0, t3 = 0;
    for (int i = 1; i <= ab; i++)
        t1 += comb.Com(a, i) * comb.Com(b, i) * comb.fac(i);
    for (int i = 1; i <= bc; i++)
        t2 += comb.Com(b, i) * comb.Com(c, i) * comb.fac(i);
    for (int i = 1; i <= ac; i++)
        t3 += comb.Com(a, i) * comb.Com(c, i) * comb.fac(i);
    ans += t1 + t2 + t3;
    ans += t1 * t2 + t2 * t3 + t3 * t1;
    ans += t1 * t2 * t3;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}