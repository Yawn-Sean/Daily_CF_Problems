#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int n = a.size();

    a = " " + a, b = " " + b;

    vector<int> dp(n + 2);
    for (int i = 1; i <= n; i++) {
        int l = max(1, i - n / 100), r = min(n, i + n / 100);
        for (int j = r; j >= l; j--) {
            if (a[i] == b[j]) {
                dp[j + 1] = max(dp[j + 1], dp[j] + 1);
            }
        }
        for (int j = l; j <= r; j++) {
            dp[j + 1] = max(dp[j + 1], dp[j]);
        }
    }

    if (*rgs::max_element(dp) * 100 >= n * 99) {
        cout << "Long lost brothers D:";
    } else {
        cout << "Not brothers :(";
    }
    return 0;
}