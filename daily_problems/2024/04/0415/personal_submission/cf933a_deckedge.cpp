#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main(){
    int n = red(), res = 0;

    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>> (n));
    vector<int> a(n), pre(n), suf(n);

    generate(all(a), red);
    pre[0] = (a[0] == 1);
    suf[n - 1] = (a[n - 1] == 2);
    for(int i = 1;i<n;i++) {
        pre[i] = pre[i-1] + (a[i] == 1);
    }
    for(int i= n-2;i >= 0; i--) {
        suf[i] = suf[i+1] + (a[i] == 2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++){
            if (!j) {
                dp[i][j][1] = (a[j] == 2);
                dp[i][j][0] = (a[j] == 1);
            } else if (j) {
                dp[i][j][1] = dp[i][j-1][1] + (a[j] == 2);
                dp[i][j][0] = max(dp[i][j-1][0], dp[i][j-1][1]) + (a[j] == 1);
            }


            if (!i && j == n - 1) {

                res = max(dp[i][j][0], res);
                res = max(dp[i][j][1], res); 
            } else if (!i) {
                res = max(dp[i][j][0] + suf[j + 1], res);
                res = max(dp[i][j][1] + suf[j + 1], res);
            } else if (j == n - 1) {
                res = max(dp[i][j][0] + pre[i - 1], res);
                res = max(dp[i][j][1] + pre[i - 1], res);
            } else if (i && j != n - 1) {
                res = max(dp[i][j][0] + pre[i - 1] + suf[j + 1], res);
                res = max(dp[i][j][1] + pre[i - 1] + suf[j + 1], res);
            }

        }
    }

    cout << res << '\n';
    return 0;
}