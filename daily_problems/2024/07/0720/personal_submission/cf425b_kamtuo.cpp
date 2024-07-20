/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-20 14:01 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123;

int main() {
    int ans = 0x3f3f3f3f;
    int n, m, k;
    cin >> n >> m >> k;
    vector mp(N, vector (N, -1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> mp[i][j];
        }
    }
    if (n > k) {
        for (int i = 1; i <= n; i ++) {
            int res = 0;
            for (int j = 1; j <= n; j ++) {
                int now = 0;
                for (int sk = 1; sk <= m; sk ++) {
                    now += (mp[j][sk] != mp[i][sk]);
                }
                now = min(m - now, now);
                res += now;
            }
            ans = min(ans, res);
        }
    } else {
        vector back(N, 0);
        for (int i = 0; i < 1 << n; i ++) {
            int res = 0;
            for (int j = 0; j < n; j ++) {
                back[j + 1] = (i >> j) % 2;
            }
            for (int j = 1; j <= n; j ++) {
                res += (back[j] != mp[j][1]);
            }
            for (int j = 2; j <= m; j ++) {
                int now = 0;
                for (int sk = 1; sk <= n; sk ++) {
                    now += (back[sk] != mp[sk][j]);
                }
                now = min(now, n - now);
                res += now;
            }
            ans = min(res, ans);
        }
    }
    if (ans <= k) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}

/*

*/
