/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-26 19:35 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int N = n + 1;
    vector p(N, 0), st(N, 0);
    int cnt = 0;
    for (int i = 2; i <= n; i ++) {
        if (st[i] == 0) p[cnt ++] = i;
        for (int j = 0; i * p[j] <= n; j ++) {
            st[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
    auto find = [&] (int x) -> int {
        return upper_bound(p.begin(), p.begin() + cnt, x) - p.begin();
    };
    vector a(N, 0), pos(N, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<std::pair<int, int>> ans;
    for (int i = 1; i <= n; i ++) {
        while (pos[i] != i) {
            int len = pos[i] - i + 1;
            int x = find(len) - 1;
            std::swap(a[pos[i]], a[pos[i] - p[x] + 1]);
            ans.push_back({pos[i], pos[i] - p[x] + 1});
            pos[a[pos[i]]] = pos[i];
            pos[i] = pos[i] - p[x] + 1;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].second << ' ' <<  ans[i].first << endl;
    }
    return 0;
}

#endif

/*

*/
