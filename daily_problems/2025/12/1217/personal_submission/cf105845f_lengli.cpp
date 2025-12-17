#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        vector<int> next_dp(n + 1, 0);
        vector<int> bucket(i, 0);

        int cur = 0;
        for (int j = 0; j <= n; ++j) {
            cur = (cur + j) % i;
            next_dp[j] = bucket[cur];
            bucket[cur] = (bucket[cur] + dp[j]) % MOD;
        }

        dp.swap(next_dp);
        answer = (answer + dp[n]) % MOD;
    }

    cout << answer << '\n';
    return 0;
}
