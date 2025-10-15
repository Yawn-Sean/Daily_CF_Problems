/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-13 19:34 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector edge(n + 1, vector<int>());
    int root = 0;
    if (n % 2 == 0) {
        cout << "NO" << "\n";
        return 0;
    }
    vector dep(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (!x) root = i;
        else {
            edge[x].push_back(i);
            dep[x] ^= 1;
            dep[i] ^= 1;
        }
    }
    cout << "YES\n";
    vector st(n + 1, 0);
    std::function<void (int)> print = [&] (int now) {
        if (st[now]) return;
        st[now] = 1;
        cout << now << "\n";
        for (auto v : edge[now]) {
            print(v);
        }
    };
    std::function<void (int, int)> dfs = [&] (int now, int fa) {
        for (int i = 0; i < edge[now].size(); i ++) {
            dfs(edge[now][i], now);
        }
        if (!dep[now]) {
            if (fa != -1) dep[fa] ^= 1;
            print(now);
        }
    };
    dfs(root, -1);
    return 0;
}

#endif

/*

*/
