/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-11 08:06 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int r, c;
        cin >> r >> c;
        vector<string> mp(r);
        for (int i = 0; i < r; i ++) cin >> mp[i];
        int ans = 5;
        int cnt = 0;
        if (mp[0][0] == 'A' || mp[0][c - 1] == 'A' || mp[r - 1][0] == 'A' || mp[r - 1][c - 1] == 'A') ans = min(ans, 2);
        for (int i = 0; i < r; i ++) {
            bool ok = true;
            for (int j = 0; j < c; j ++) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    if (mp[i][j] == 'A') ans = min(ans, 3);
                }
                if (mp[i][j] == 'A') ans = min(ans, 4), cnt ++;
                if (mp[i][j] == 'P') ok = false;
            }
            if (ok) {
                if (i == 0 || i == r - 1) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        for (int i = 0; i < c; i ++) {
            bool ok = true;
            for (int j = 0; j < r; j ++) {
                if (mp[j][i] == 'P') ok = false;
            }
            if (ok) {
                if (i == 0 || i == c - 1) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        if (cnt == r * c) ans = min(ans, 0); 
        if (ans == 5) cout << "MORTAL\n";
        else cout << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
