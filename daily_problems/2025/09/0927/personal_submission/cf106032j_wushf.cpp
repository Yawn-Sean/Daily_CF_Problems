#include <bits/stdc++.h>
#include <cmath>

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
// #define double long double
// #define acos acosl
// #define sqrt sqrtl
// #define sin sinl
// #define cos cosl
#define pii pair<int, int>
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const double PI = acos(-1);
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> nums(n), cnt(m + 1);
    for (auto& x : nums) {
        cin >> x;
        cnt[x] ^= 1;
    }
    vector<int> nextOdd(m + 1, 1e9);
    for (int i = 0; i <= m; i++) {
        if (cnt[i])
            nextOdd[i] = 0;
    }
    for (int i = m; i > 0; i--)
        nextOdd[i - 1] = min(nextOdd[i - 1], nextOdd[i] + 1);
    nextOdd[m] = min(nextOdd[m], nextOdd[0]);
    for (int i = m; i > 0; i--)
        nextOdd[i - 1] = min(nextOdd[i - 1], nextOdd[i] + 1);
    int c = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            c++;
        } else {
            int idx;
            cin >> idx;
            int x = nums[idx - 1];
            int step = min(nextOdd[x], c);
            cout << (x + step - 1) % m + 1 << endl;
        }
    }
}

signed main() {
    IOS;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}