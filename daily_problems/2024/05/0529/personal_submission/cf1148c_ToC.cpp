// https://codeforces.com/contest/1148/submission/263333449
int n, m;
int i2v[MAXN], v2i[MAXN];
int cnt, eq;
bool vis[MAXN];
vector<PII> history;
void op(int x, int y) {
    int ix = v2i[x], iy = v2i[y];
    history.push_back({ix, iy});
    v2i[x] = iy, v2i[y] = ix;
    i2v[ix] = y, i2v[iy] = x; 
    cnt++;
}
void sol_new()
{
    cin >> n;
    int v;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        i2v[i] = v;
        v2i[v] = i;
        if (i == v){
            eq++;
            vis[i] = true;
        }
    }
    if (eq == n) {
        cout << 0 << '\n';
        return ;
    }
    int half = n / 2;
    for (int v = 1; v <= half; v++) {
        int i = v2i[v];
        if (v != i) {
            // 当前下标i, 目标下标v
            if (i <= half) {
                op(v, i2v[n]);
                op(v, i2v[v]);
                op(i2v[n], i2v[i]);
            } else {
                if (abs(v - i) >= half) {
                    op(v, i2v[v]);
                } else {
                    op(v, i2v[1]);
                    op(v, i2v[n]);
                    op(v, i2v[v]);
                    op(i2v[1], i2v[n]);
                    op(i2v[1], i2v[i]);
                }
            }
        }
    }
    for (int i = half + 1; i <= n; i++) {
        int v = i2v[i];
        while (v != i) {
            op(i2v[1], v);
            op(v, i2v[v]);
            op(i2v[1], i2v[i]);
            v = i2v[i];
        }
    }
    cout << cnt << '\n';
    for (auto &[l, r] : history) {
        cout << l << " " << r << '\n';
    }
}
