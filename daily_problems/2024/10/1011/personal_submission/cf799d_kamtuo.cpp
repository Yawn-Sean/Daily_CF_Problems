/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-11 19:49 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    if ((h >= a && w >= b) || (w >= a && h >= b)) {
        cout << 0 << "\n";
        return 0;
    } 
    vector ai(n, 0);
    for (int i = 0; i < n; i ++) cin >> ai[i];
    sort(ai.begin(), ai.end(), [&] (int x, int y) {return x > y;});
    vector st(111111, 0);
    for (int i = 1; i <= n; i ++) {
        int cnt = 0;
        bool ok = false;
        LL now = 1;
        map<int, int> mp;
        for (int j = 1; j <= 100000; j ++) st[j] = 0;
        for (int j = 0; j < i; j ++) {
            if (st[ai[j]] == 0) cnt ++, mp[cnt] = ai[j];
            st[ai[j]] ++;
            now *= ai[j];
            if (now >= 1e10) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << i << "\n";
            return 0;
        }
        if (cnt >= 15) ok = true;
        vector to(cnt + 1, vector<LL> (1, 1ll));
        for (auto [key, value] : mp) {
            for (int j = 1; j <= st[value]; j ++) {
                to[key].push_back(1ll * to[key].back() * value);
            }
        }
        std::function<void (int, int)> dfs = [&] (int in, LL sum) {
            if (in > cnt) {
                if (1ll * h * sum >= a && 1ll * w * (now / sum) >= b) ok = true;
                if (1ll * w * sum >= a && 1ll * h * (now / sum) >= b) ok = true;
                return;
            }
            for (int i = 0; i < to[in].size(); i ++) {
                dfs(in + 1, sum * to[in][i]);
            }
        };
        dfs(1, 1);
        if (ok) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}

#endif

/*

*/
