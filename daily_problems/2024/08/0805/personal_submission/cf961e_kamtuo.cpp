/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-05 17:00 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0), tr(n + 1, 0);
    vector cnt(n + 1, vector<int>());
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] = min(a[i], n);
        cnt[a[i]].push_back(i);
    }
    std::function<int (int x)> lowbit = [&] (int x) -> int {
        return x & -x;
    };
    std::function<void (int x)> add = [&] (int x) -> void {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] ++;
    };
    std::function<int (int x)> query = [&] (int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    };
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        add(a[i]);
        for (int j = 0; j < cnt[i].size(); j ++) {
            ans += query(n) - query(cnt[i][j] - 1);
            if (cnt[i][j] <= i) ans --;
        }
    } 
    cout << (ans >> 1ll) << endl;
    return 0;
}

#endif

/*

*/
