#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int sum = 0, cnt = 0;
    for (int i = 0; i < n * 2; ++i) {
        int val;
        char ch;
        cin >> val >> ch >> val;

        if (val > 0) {
            sum += val;
            cnt++;
        }
    }

    int ans = INT_MAX;
    for (int i = max(cnt - n, 0); i <= min(cnt, n); ++i) {
        ans = min(ans, abs(i * 1000 - sum));
    }

    cout << ans / 1000 << "." << setw(3) << setfill('0') << ans % 1000 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
