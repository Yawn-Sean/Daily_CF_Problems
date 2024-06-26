#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    ll k;
    int a, b;
    cin >> k >> a >> b;
    int A[4][4], B[4][4];
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
            cin >> A[i][j];
    for (int i = 1; i < 4; i++)
        for (int j = 1; j < 4; j++)
            cin >> B[i][j];
    map<pair<int, int>, ll> mp;
    map<pair<int, int>, ll> sa, sb;
    ll step = 1;
    ll alice = 0, bob = 0;
    while (k > 0) {
        if (mp.count({a, b})) {
            int c = step - mp[{a, b}];
            ll tmp = k / c;
            if (tmp != 0) {
                k %= c;
                alice += tmp * (alice - sa[{a, b}]);
                bob += tmp * (bob - sb[{a, b}]);
            }
            if (k == 0) {
                break;
            }
        }
        sa[{a, b}] = alice;
        sb[{a, b}] = bob;
        mp[{a, b}] = step;
        if (a == b) {
        } else if ((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3)) {
            alice++;
        } else {
            bob++;
        }
        step++;
        int ta = A[a][b], tb = B[a][b];
        a = ta, b = tb;
        k--;
    }
    cout << alice << " " << bob << endl;
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