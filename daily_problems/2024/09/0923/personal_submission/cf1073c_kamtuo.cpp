/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-23 14:33 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ex, ey;
    cin >> ex >> ey;
    if (abs(ex) + abs(ey) > n) {
        cout << -1 << "\n";
        return 0;
    }
    vector cnt(4, vector (n + 1, 0)); // U D L R
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'U') cnt[0][i + 1] = 1;
        else if (s[i] == 'D') cnt[1][i + 1] = 1;
        else if (s[i] == 'L') cnt[2][i + 1] = 1;
        else cnt[3][i + 1] = 1;
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 1; j <= n; j ++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    auto check = [&] (int mid) -> bool {
        if (mid == 0) {
            if (cnt[3][n] - cnt[2][n] == ex && cnt[0][n] - cnt[1][n] == ey) return true;
            return false;
        }
        for (int i = 1; i + mid - 1 <= n; i ++) {
            vector now(4, 0);
            for (int j = 0; j < 4; j ++) {
                now[j] = cnt[j][n] - (cnt[j][i + mid - 1] - cnt[j][i - 1]);
            }
            int x = now[3] - now[2], y = now[0] - now[1];
            int dx = abs(ex - x), dy = abs(ey - y);
            if (mid >= dx + dy) {
                if ((mid - dx) % 2 == dy % 2) return true;
            }
        }
        return false;
    };
    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (check(r)) cout << r << "\n";
    else cout << -1 << "\n";
    return 0;
}

#endif

/*

*/
