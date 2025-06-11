/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-23 15:57 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a;
    cin >> n >> a;
    vector co(n, 0);
    for (int i = 0; i < n; i ++) cin >> co[i];
    vector<vector<int>> cn(n + 1);
    vector cnt(1111111, 0);
    int now = 0;
    for (int i = 0; i < n; i ++) {
        if (cnt[co[i]] < now) continue;
        cnt[co[i]] ++;
        if (co[i] == a) {
            now = cnt[co[i]];
        } else {
            cn[cnt[co[i]]].push_back(co[i]);
        }
    }
    for (int i = now; i <= n; i ++) {
        if (cn[i].size()) {
            cout << cn[i][0] << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}

#endif

/*

*/
