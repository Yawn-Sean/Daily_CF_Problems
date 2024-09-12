/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-11 14:54 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int b, d;
    cin >> b >> d;
    string a, c;
    cin >> a >> c;
    int n = a.size(), m = c.size();
    vector cnt(n, 0), loc(n, 0);
    for (int i = 0; i < m; i ++) {
        bool have = false;
        for (int j = 0; j < n; j ++) {
            if (a[j] == c[i]) have = true;
        }
        if (have == false) {
            cout << 0 << '\n';
            return 0;
        } 
    }
    for (int i = 0; i < n; i ++) {
        int k = 0;
        for (int j = i; k < m; j ++) {
            if (j >= n) {
                j = 0;
                cnt[i] ++;
            }
            if (c[k] == a[j]) k ++;
            if (k == m) {
                loc[i] = j;
            }
        } 
        if (cnt[i] == 0) {
            int l = 0, r = i;
            while (r < n) {
                while (r < n && a[r] != c[l]) r ++;
                if (r == n) break;
                l ++;
                if (l == m) cnt[i] --, loc[i] = r, l = 0;
                r ++;
            }
            // debug("cnt:", cnt[i]);
        }
    }
    int now = 0, idx = 0, ans = 0, res = 0;
    while (now <= b) {
        // debug("idx:", idx);
        if (idx == 0) now ++;
        if (cnt[idx] < 0) {
            ans -= cnt[idx];
            // debug("cnt:", cnt[idx]);
            // now ++;
        } else {
            now += cnt[idx];
            ans ++;
        }
        idx = (loc[idx] + 1) % n;
        if (now > b) break;
        res = ans;
    }
    cout << res / d << '\n';
    return 0;
}

#endif

/*

*/
