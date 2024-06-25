// https://codeforces.com/contest/1949/submission/264381331
int n, m, k;
struct CIR {
    double x, y, r;
};
CIR cirs[MAXN];
vector<int> g[MAXN];
int color[MAXN], k1, k2;
bool dfs(int cur, int col) {
    color[cur] = col;
    if (col == 1) k1++;
    else k2++;
    bool res = true;
    for (auto &chd : g[cur]) {
        if (color[chd]) {
            if (color[chd] == col) res = false;
        } else {
            res = dfs(chd, 3 - col) && res;  // 感谢村长指点错误原因
        }
    }   
    return res;
}
bool isTan(int i, int j) {
    double d1 = (cirs[i].r + cirs[j].r) * (cirs[i].r + cirs[j].r);
    double d2 = (cirs[i].x - cirs[j].x) * (cirs[i].x - cirs[j].x) + (cirs[i].y - cirs[j].y) * (cirs[i].y - cirs[j].y);
    return d1 == d2;
}
void sol()
{
    cin >> n;
    double x, y, r;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> r;
        cirs[i] = {x, y, r};
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (isTan(i, j))
                g[j].push_back(i), g[i].push_back(j);
        }
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            k1 = 0, k2 = 0;
            if (dfs(i, 1)) {
                if (k1 != k2) {
                    ok = true;
                    break;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
}
