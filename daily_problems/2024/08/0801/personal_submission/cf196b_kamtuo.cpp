/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-01 19:12 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    vector idx = {0, 0, 1, -1}, idy = {1, -1, 0, 0};
    vector st(n, vector(m, std::make_pair(1000 * 1000, 1000 * 1000)));
    queue<std::pair<int, int>> q;
    for (int i = 0; i < n; i ++) cin >> mp[i];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] == 'S') {
                q.push({i, j});
                st[i][j].first = i;
                st[i][j].second = j;
                break;
            }
        }
    }
    bool ok = false;
    while (!q.empty()) {
        std::pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = now.first + idx[i], ny = now.second + idy[i];
            int cx = nx % n + n, cy = ny % m + m;
            cx %= n, cy %= m;
            if (mp[cx][cy] == '#') continue;
            if (st[cx][cy].first != 1000000 && (st[cx][cy].first != nx || st[cx][cy].second != ny)) {
                ok = true;
                break;
            }
            if (st[cx][cy].first != 1000000) continue;
            st[cx][cy].first = nx;
            st[cx][cy].second = ny;
            q.push({nx, ny});
        }
    }
    if (ok) cout << "Yes";
    else cout << "No";
    return 0;
}

#endif

/*

*/
