/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-30 16:41 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, l, r;
    cin >> n >> l >> r;
    vector<LL> now;
    for (LL i = l; i <= r; i ++) {
        now.push_back(i);
    }
    LL k = n;
    vector to(55, 0);
    int cnt = 0;
    while (k > 1) {
        to[cnt ++] = k % 2;
        k /= 2;
    }
    int ans = 0;
    // debug("cnt:", cnt);
    while (now.size()) {
        vector<LL> ne;
        -- cnt;
        for (int i = 0; i < now.size(); i ++) {
            if (now[i] % 4 == 0) {
                ne.push_back(now[i] / 2);
            } else {
                if (now[i] % 2) ans += k;
                else ans += to[cnt];
                // debug("cnt:", cnt);
            }
        }
        // debug("ne:", ne);
        now = ne;
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
