#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), cnt(11);
    for (int &ai : a) {
        cin >> ai;
        int mid = 0, x = ai;
        while (x) {
            x /= 10;
            ++mid;
        }
        cnt[mid]++;
    }
    for (int ai : a) {
        int x = ai, y = 0, mid = 1;
        for (int i = 1; i <= 10; ++i) {
            y = (y + x % 10 * mid) % mod;
            x /= 10;
            ans = (ans + (x * 10 * mid + y) % mod * cnt[i] * 10) % mod;
            ans = (ans + (x * 100 * mid + y) % mod * cnt[i]) % mod;
            mid = mid * 100 % mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
