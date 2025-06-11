/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-19 17:33 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 2234, M = 512345, L = 12345678;

bool st[M];
bool pa[N][N];
int in[M];
int p[M];
vector<int> ans[M], t, nums;
int cnt[M];
int n, m;
int tot;

struct Node {
    int u, v;
} tr[L];

int find(int x) {
    return lower_bound(t.begin(), t.end(), x) - t.begin();
}

int find2(int x) {
    if (p[x] - x) p[x] = find2(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i ++) p[i] = i;
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d", &tr[i].u, &tr[i].v);
        in[tr[i].u] ++;
        in[tr[i].v] ++;
    }
    for (int i = 1; i <= n; i ++) {
        if (in[i] <= 2000) {
            for (int j = 1; j <= m; j ++) {
                if (tr[j].u == i || tr[j].v == i) {
                    st[tr[j].u] = true;
                    st[tr[j].v] = true;
                }
            }
            st[i] = false;
            break;
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (st[i]) {
            t.push_back(i);
        } else {
            int fi = find2(i);
            p[fi] = 0;
        } 
    }
    for (int i = 1; i <= m; i ++) {
        int u = tr[i].u, v = tr[i].v;
        if (st[u] && st[v]) {
            int fu = find(u), fv = find(v);
            pa[fu][fv] = pa[fv][fu] = true;
            cnt[u] ++;
            cnt[v] ++;
        }
    }
    int cur = n - t.size();
    for (int i = 0; i < t.size(); i ++) {
        int now = t[i];
        if (in[now] - cnt[now] < cur) {
            int fnow = find2(now);
            p[fnow] = 0;
        }
    }
    for (int i = 0; i < t.size(); i ++) {
        int nowi = t[i];
        for (int j = 0; j < t.size(); j ++) {
            int nowj = t[j];
            if (!pa[i][j]) {
                int fi = find2(nowi), fj = find2(nowj);
                if (fi != fj) {
                    p[fi] = fj;
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        int fi = find2(i);
        ans[fi].push_back(i);
    }
    int res = 0;
    for (int i = 0; i <= n; i ++) {
        if (ans[i].size()) {
            res ++;
        }
    }
    cout << res << endl;
    for (int i = 0; i <= n; i ++) {
        if (ans[i].size()) {
            cout << ans[i].size() << ' ';
            for (int j = 0; j < ans[i].size(); j ++) {
                cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
            }
        }
    }
    return 0;
}

/*

*/
