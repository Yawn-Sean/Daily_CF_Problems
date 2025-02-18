/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-29 20:44 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> mp(n);
    vector<int> s(p);
    vector st(n, vector(m, -1)), to(n, vector(m, 0)), ki(n, vector(m, 0));
    vector pos(p, vector<std::pair<int, int>>());
    queue<Node> q;
    for (int i = 0; i < p; i ++) cin >> s[i];
    for (int i = 0; i < n; i ++) {
        cin >> mp[i];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] >= '1' && mp[i][j] <= '9') {
                st[i][j] = mp[i][j] - '0' - 1;
                pos[mp[i][j] - '0' - 1].push_back({i, j});
                // pos[mp[i][j] - '0' - 1] = {i, j};
            }
        }
    }

    for (int i = 0; i < p; i ++) {
        for (int j = 0; j < pos[i].size(); j ++) {
            q.push({pos[i][j].first, pos[i][j].second, i});
        }
        pos[i].clear();
    }
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        debug("now.num=", now.num);
        // to[now.x][now.y] = true;
        queue<Node> qq;
        qq.push({now.x, now.y, 0});
        while (!q.empty() && q.front().num == now.num) {
            qq.push({q.front().x, q.front().y, 0});
            q.pop();
        }
        while (!qq.empty()) {
            Node next = qq.front();
            qq.pop();
            if (next.num == s[now.num]) {
                q.push({next.x, next.y, now.num});
                continue;
            }
            for (int i = 0; i < 4; i ++) {
                int nx = next.x + idx[i], ny = next.y + idy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (st[nx][ny] != -1) continue;
                if (mp[nx][ny] == '#') continue;
                st[nx][ny] = now.num;
                qq.push({nx, ny, next.num + 1});
            }
        }
    }
    vector ans(p, 0);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (st[i][j] != -1) {
                if (st[i][j] == 1) {
                    // debug("i = ", i, "j = ", j);
                }
                ans[st[i][j]] ++;
            }
        }
    }
    for (int i = 0; i < p; i ++) cout << ans[i] << ' ';
    return 0;
}


/*

*/
