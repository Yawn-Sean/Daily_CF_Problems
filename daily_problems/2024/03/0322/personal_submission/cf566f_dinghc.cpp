#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int MXN = 1e6 + 1;
int dp[MXN];
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    dp[1] = a[1];
    for (int i = 1; i < MXN; i++) {
        for (int p = i * 2; p < MXN; p += i) {
            dp[p] = max(dp[p], dp[i] + a[p]);
        }
    }
    
    cout << *max_element(dp, dp + MXN) << "\n";

    return 0;
}

