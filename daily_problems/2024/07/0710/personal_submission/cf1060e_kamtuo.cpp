/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-10 18:37 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 412345;

int n, ne[N], idx = 1, d[N], h[N];
LL ans, cnt;
int dp[N][2], sz[N];

void add(int u, int v) {
    ne[idx] = h[u];
    d[idx] = v;
    h[u] = idx ++;
}

void dfs(int now, int fa) {
    dp[now][0] = 1;
    sz[now] = 1;
    for (int i = h[now]; i; i = ne[i]) {
        int j = d[i];
        if (j == fa) continue;
        dfs(j, now);
        sz[now] += sz[j];
        cnt += 1ll * dp[j][1] * dp[now][1] + 1ll * dp[j][0] * dp[now][0];
        dp[now][1] += dp[j][0];
        dp[now][0] += dp[j][1];

    }
    ans += 1ll * (n - sz[now]) * sz[now];
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
    cout << (ans + cnt) / 2ll << endl;
    return 0;
}

/*

*/
