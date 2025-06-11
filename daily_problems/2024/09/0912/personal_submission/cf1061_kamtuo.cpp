/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-12 18:57 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    const int MOD = 1e9 + 7;
    vector<std::pair<int, int>> lr(n);
    for (int i = 0; i < n; i ++) {
        cin >> lr[i].first >> lr[i].second;
    }
    sort(lr.begin(), lr.end());
    int ans = 0;
    priority_queue<int, vector<int>, std::greater<int>> pqin;
    priority_queue<int> pqout;
    for (int i = 0; i < n; i ++) {
        while (!pqin.empty() && pqin.top() < lr[i].first) {
            pqout.push(pqin.top());
            pqin.pop();
        }
        if (!pqout.empty() && (1ll * lr[i].first - pqout.top()) * y <= x) {
            ans += ((1ll * (1ll * lr[i].first - pqout.top()) * y % MOD) % MOD + 1ll * (lr[i].second - lr[i].first) * y % MOD) % MOD;
            ans %= MOD;
            pqout.pop();
        } else {
            ans += (x + 1ll * (lr[i].second - lr[i].first) * y % MOD) % MOD;
            ans %= MOD;
        }
        pqin.push(lr[i].second);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
