/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-29 14:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 523450;

int ne[N << 1], d[N << 1], idx = 1, h[N << 1];
vector<int> v[N];
int n, m;
int ans[N];
int cnt;
bool st[N];

void add(int u, int v) {
    ne[idx] = h[u];
    d[idx] = v;
    h[u] = idx ++;
}

void dfs(int now, int fa) {
    vector<int> j1;
    for (int i = 1; i <= v[now].size(); i ++) st[i] = false;
    for (int i = 0; i < v[now].size(); i ++) {
        if (ans[v[now][i]] && ans[v[now][i]] <= v[now].size()) st[ans[v[now][i]]] = true; 
        if (ans[v[now][i]] == 0) j1.push_back(v[now][i]);
    }
    for (int i = 1, j = 0; j < j1.size() && i <= v[now].size(); i ++) {
        if (st[i] == false) {
            ans[j1[j]] = i;
            cnt = max(cnt, i);
            j ++;
        }
    }
    for (int i = h[now]; i; i = ne[i]) {
        int j = d[i];
        if (j == fa) continue;
        dfs(j, now);
    }

}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int c; 
        scanf("%d", &c);
        for (int j = 1; j <= c; j ++) {
            int color;
            scanf("%d", &color);
            v[i].push_back(color);
        }
    } 
    for (int i = 1; i < n; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
    cout << (cnt ? cnt : 1) << endl;
    for (int i = 1; i <= m; i ++) cout << (ans[i] ? ans[i] : 1) << ' ';

    return 0;
}

/*

*/
