#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(10, vector<int>(10, 1e9));

    auto check = [&](int a, int b) {
        dp.assign(10, vector<int>(10, 1e9));
        for (int last = 0; last <= 9; last++) {
            for (int cur = 0; cur <= 9; cur++) {
                for (int x = 0; x <= 10; x++) {
                    for (int y = 0; y <= 10; y++) {
                        if (x + y == 0) {
                            continue;
                        }
                        int tmp = last + a * x + b * y;
                        if (tmp % 10 == cur) {
                            dp[last][cur] = min(dp[last][cur], x + y - 1);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int last = s[i] - '0';
            int cur = s[i + 1] - '0';
            if (dp[last][cur] == 1e9) {
                return -1;
            } else {
                ans += dp[last][cur];
            }
        }
        return ans;
    };

    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            cout << check(a, b) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
