const int N = 2e3 + 5;

int k, n;
double p[N][N], f[N][N], g[N][N];

#define lc(u) (u << 1)
#define rc(u) (u << 1 | 1)
void dfs(int u, int l, int r) {
    if(l == r) {
        f[u][l] = 0.0;
        g[u][l] = 1.0;
        return;
    }
    int mid = (l + r) >> 1;
    dfs(lc(u), l, mid);
    dfs(rc(u), mid + 1, r);
    rep(i, l, mid) {
        rep(j, mid + 1, r) {
            g[u][i] += g[lc(u)][i] * g[rc(u)][j] * p[i][j];
            g[u][j] += g[lc(u)][i] * g[rc(u)][j] * p[j][i];
        }
    }
    rep(i, l, mid) {
        rep(j, mid + 1, r) {
            chkmax(f[u][i], f[lc(u)][i] + f[rc(u)][j] + g[u][i] * (r - l + 1) / 2);
            chkmax(f[u][j], f[lc(u)][i] + f[rc(u)][j] + g[u][j] * (r - l + 1) / 2);
        }
    }
}
#undef lc
#undef rc

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);
    cin >> k; n = 1 << k;
    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> p[i][j];
            p[i][j] *= 0.01;
        }
    }
    dfs(1, 1, n);
    double ans = 0.0;
    rep(i, 1, n) chkmax(ans, f[1][i]);
    cout << ans << endl;
    return 0;
}
