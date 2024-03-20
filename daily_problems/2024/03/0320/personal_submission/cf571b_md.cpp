#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr long long inf = 1e16;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    copy_n(istream_iterator<ll>(cin), n, begin(a));

    sort(begin(a), end(a));

    int len_a = k - n % k;
    int len_b = n % k;
    int group_len_a = n / k;
    int group_len_b = n / k + 1;
    
    // dp[i][j] min value while i is the num of len == n/k, j is the num of len == n/k + 1
    vector<vector<ll>> dp(len_a + 1, vector<ll>(len_b + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i <= len_a; ++i) {
        for (int j = 0; j <= len_b; ++j) {
            auto&& group_offset = i * group_len_a + j * group_len_b - 1;
            if (i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + a[group_offset] - a[group_offset - group_len_a + 1]);
            }
            if (j) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + a[group_offset] - a[group_offset - group_len_b + 1]);
            }
        }
    }
    
    cout << dp[len_a][len_b] << endl;

    return 0;
}