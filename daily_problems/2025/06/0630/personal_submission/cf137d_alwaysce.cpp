#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.size();
    vector<vector<int>> num_op(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int c1 = i, c2 = i;
        while (c1 >= 0 && c2 < n) {
            int add = (s[c1] != s[c2]);
            num_op[c1][c2] = ((c1 + 1 <= c2 - 1) ? num_op[c1 + 1][c2 - 1] : 0) + add;
            c1--;
            c2++;
        }

        c1 = i, c2 = i + 1;
        while (c1 >= 0 && c2 < n) {
            int add = (s[c1] != s[c2]);
            num_op[c1][c2] = ((c1 + 1 <= c2 - 1) ? num_op[c1 + 1][c2 - 1] : 0) + add;
            c1--;
            c2++;
        }
    }

    int inf = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
    vector<vector<int>> from(n + 1, vector<int>(k + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int l = k; l >= 1; l--) {
                int ndp = dp[j][l - 1] + num_op[j][i - 1];
                if (ndp < dp[i][l]) {
                    dp[i][l] = ndp;
                    from[i][l] = j;
                }
            }
        }
    }

    int ans_num = inf, ans_change = inf;
    for (int l = 1; l <= k; l++) {
        if (dp[n][l] < ans_change) {
            ans_num = l;
            ans_change = dp[n][l];
        }
    }


    cout << ans_change << endl;
    vector<string> segs;
    
    int cur = n, cur_num = ans_num;
    while (cur != -1) {
        int pre = from[cur][cur_num];
        cur_num--;
        if (pre != -1) segs.push_back(s.substr(pre, cur - pre));
        cur = pre;
    }

    auto reformat = [](string &s) {
        int m = s.size();
        int c1 = (m - 1) / 2, c2 = m / 2;
        while (c1 >= 0 && c2 < m) {
            if (s[c1] != s[c2]) {
                s[c1] = s[c2];
            }
            c1--;
            c2++;
        }
    }; 

    reverse(segs.begin(), segs.end());
    for (int i = 0; i < (int)segs.size(); i++) {
        reformat(segs[i]);
        cout << segs[i];
        if (i < (int)segs.size() - 1) {
            cout << "+";
        }
    }
    cout << endl;
    return 0;
}
