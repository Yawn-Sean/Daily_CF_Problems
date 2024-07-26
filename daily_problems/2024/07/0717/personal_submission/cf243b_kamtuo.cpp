/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-17 18:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 212345;

int ne[N], idx = 1, h[N], d[N];
int cnt;
int n, m, s, t;
int st[N];

struct Node {
    int u, v;
} path[N];

void add(int u, int v) {
    ne[idx] = h[u];
    d[idx] = v;
    h[u] = idx ++;
}

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
        path[cnt ++] = {u, v};
        path[cnt ++] = {v, u};
    }
    for (int i = 0; i < cnt; i ++) {
        int u = path[i].u, v = path[i].v;
        st[u] = st[v] = 3;
        vector<int> now;
        now.push_back(u);
        now.push_back(v);
        int l = 0;
        for (int j = h[u]; j; j = ne[j]) {
            if (st[d[j]]) continue;
            if (now.size() == s + 2) break;
            l = j;
            st[d[j]] = 1;
            now.push_back(d[j]);
        }
        if (now.size() < s + 2) {
            for (int j = 0; j < now.size(); j ++) st[now[j]] = 0;
            continue;
        } 
        int now_c = 0;
        for (int j = h[v]; j; j = ne[j]) {
            if (now_c == t) break;
            if (d[j] == u || d[j] == v) continue;
            if (st[d[j]]) {
                if (l == 0) break;
                for (; l; l = ne[l]) {
                    if (d[l] == u || d[l] == v) continue;
                    if (st[d[l]]) continue;
                    st[d[l]] = 1;
                    now.push_back(d[l]);
                    now_c ++;
                    st[d[j]] = 2;
                    break;
                }
            } else {
                st[d[j]] = 2;
                now_c ++;
                now.push_back(d[j]);
            }
        }
        if (now_c == t) {
            cout << "YES" << endl;
            cout << u << ' ' << v << endl;
            for (int i = 1; i <= n; i ++) if (st[i] == 1) cout << i << ' ';
            cout << endl;
            for (int i = 1; i <= n; i ++) if (st[i] == 2) cout << i << ' ';
            cout << endl;
            return 0;
        }
        for (int j = 0; j < now.size(); j ++) st[now[j]] = 0;
    }
    cout << "NO" << endl;
    return 0;
}

/*

*/
