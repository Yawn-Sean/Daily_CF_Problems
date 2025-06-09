#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int inf = 1e9;
vector<vector<int>> dp(26, vector<int>(101, -inf));
vector<vector<int>> ndp(26, vector<int>(101, -inf));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int k;
    cin >> k;

    int n;
    cin >> n;

    vector<vector<int>> add(26, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        char x, y;
        int c;
        cin >> x >> y >> c;
        add[x - 'a'][y - 'a'] = c;
    }

    int m = s.size();
    for (int i = 0; i < 26; i++) {
        if (i == (s[0] - 'a')) {
            dp[i][0] = 0;
        } else {
            dp[i][1] = 0;
        }
    }

    for (int i = 1; i < m; i++) {
        int cur_ch = (s[i] - 'a');
        for (int cur = 0; cur < 26; cur++) {
            for (int last = 0; last < 26; last++) {
                for (int cnt = 0; cnt <= min(i + 1, k); cnt++) {
                    if (cur == cur_ch) {
                        ndp[cur][cnt] = max(ndp[cur][cnt], dp[last][cnt] + add[last][cur]);
                    } else {
                        if (cnt > 0) {
                            ndp[cur][cnt] = max(ndp[cur][cnt], dp[last][cnt - 1] + add[last][cur]);
                        }
                    }
                    
                }
            }
        }
        
        swap(dp, ndp);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j <= k; j++) {
                ndp[i][j] = -inf;
            }
        }
    }

    int ans = -inf;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
