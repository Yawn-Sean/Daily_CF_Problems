/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-03 09:51 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt = 0;
    int n, k;
    int now = 1;
    cin >> n >> k;
    vector ans(n, 0);
    std::function<void(int, int)> cal = [&] (int l, int r) {
        cnt ++;
        if (r - l == 1) return;
        int mid = l + r >> 1;
        cal(l, mid);
        cal(mid, r);
    };
    cal(0, n);
    std::function<void (int, int)> dfs = [&] (int l, int r) {
        if (r - l == 1) return;
        if (now == k) return;
        int mid = l + r >> 1;
        std::swap(ans[l], ans[mid]);
        sort(ans.begin() + l, ans.begin() + mid);
        sort(ans.begin() + mid, ans.begin() + r);
        now += 2;
        dfs(l, mid); 
        dfs(mid, r);
    };
    if (k > cnt || k % 2 == 0) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; i ++) ans[i] = i + 1;
        dfs(0, n);
        for (int i = 0; i < n; i ++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}

#endif

/*

*/
