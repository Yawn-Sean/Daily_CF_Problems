#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla"
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;

int C(int x, int y) {
    if (y > x) {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < y; i ++) {
        ans = ans * (x - i) / (i + 1);
    }
    return ans;
}

void solve() {
    int n, k, ans = 1;
    cin >> n >> k;
    if (k >= 2) {
        ans += C(n, 2);
    }
    if (k >= 3) {
        ans += C(n, 3) * 2;
    }
    if (k == 4) {
        ans += C(n, 4) * 9;
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
#pragma clang diagnostic pop
