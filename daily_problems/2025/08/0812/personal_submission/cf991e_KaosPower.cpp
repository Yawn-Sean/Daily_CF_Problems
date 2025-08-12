#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> comb(20, vector<long long>(20, 0));
    for (int i = 0; i < 20; i ++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; j ++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }

    string s;
    cin >> s;

    vector<int> cnt(10, 0);
    for (auto &x: s) cnt[x - '0'] ++;

    long long ans = 0;

    for (int digit = 1; digit <= s.size(); digit ++) {
        vector<long long> dp(digit + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < 10; i ++) {
            if (cnt[i]) {
                vector<long long> ndp(digit + 1, 0);

                for (int j = digit; j > 0; j --) {
                    for (int c = 1; c <= cnt[i] && c <= j; c ++) {
                        int total = digit - (j - c);
                        if (i == 0) total --;
                        if (c >= 0 && c <= total)
                            ndp[j] += dp[j - c] * comb[total][c];
                    }
                }

                dp.swap(ndp);
            }
        }

        ans += dp[digit];
    }

    cout << ans;

    return 0;
}
