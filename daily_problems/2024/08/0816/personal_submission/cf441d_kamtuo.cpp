/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-16 18:34 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    const int N = n + 1;
    vector a(N, 0), pos(N, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i], pos[a[i]] = i;
    vector edge(N, vector<int>());
    for (int i = 1; i <= n; i ++) {
        edge[i].push_back(pos[i]);
    }
    cin >> m;
    int root = 0;
    vector st(N, 0), sz(N, 0);
    vector ro(N, vector<int>());
    std::function<void(int)> dfs = [&] (int now) {
        if (st[now]) return;
        st[now] = 1;
        ro[root].push_back(now);
        for (int i = 0; i < edge[now].size(); i ++) {
            dfs(edge[now][i]);
        }
    };
    for (int i = 1; i <= n; i ++) {
        if (st[i] == 0) dfs(i), root ++;
    }
    int tot = 0;
    for (int i = 0; i < root; i ++) {
        tot += ro[i].size() - 1;
    }
    if (tot >= m) {
        // debug("root:", root);
        // if (n == 456) debug("ro0:", ro[0]);
        cout << tot - m << endl;
        struct Node {
            int he;
            int root;
            bool operator < (const Node & now) const {
                return he > now.he;
            }
        };
        priority_queue<Node> pr;
        for (int i = 0; i < root; i ++) {
            if (ro[i].size() >= 2) pr.push({ro[i][0], i});
        } 
        while (tot != m && !pr.empty()) {
            Node now = pr.top();
            pr.pop();
            int i = now.root;
            if (ro[i].size() <= 1) continue;
            int minn = n + 1, idx = 0;
            for (int j = 1; j < ro[i].size(); j ++) {
                if (minn > ro[i][j]) {
                    minn = ro[i][j];
                    idx = j;
                }
            }
            cout << ro[i][0] << ' ' << minn << ' ';
            tot --;
            // debug("ro[i]:", ro[i]);
            for (int j = idx; j < ro[i].size(); j ++) {
                ro[root].push_back(ro[i][j]);
            }
            pr.push({ro[root][0], root});
            pr.push({ro[i][0], i});
            root ++;
            while (ro[i].back() != minn) {
                ro[i].pop_back();
            }
            ro[i].pop_back();
        }
    } else {
        // debug("1");
        cout << m - tot << endl;
        for (int i = 1; i < root; i ++) {
            if (tot == m) break;
            cout << ro[0][0] << ' ' << ro[i][0] << ' ';
            tot ++;
        }
    }
    return 0;
}

#endif

/*

*/
