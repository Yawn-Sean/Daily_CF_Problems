// https://codeforces.com/contest/1592/submission/256118209
const int MAXN = 1e5 + 10;
int n, t, m, x, k, a, b;
int xum, w[MAXN];
vector<int> g[MAXN];
int subTree[MAXN];
bool ok = false;

int dfs1(int chd, int par) {
    subTree[chd] = w[chd];
    for (auto &gchd : g[chd]) {
        if (gchd != par)
            subTree[chd] ^= dfs1(gchd, chd);
    }
    return subTree[chd];
}

int dfs2(int chd, int par) {
    int cnt = 0;
    for (auto &gchd : g[chd]) {
        if (gchd != par)
            cnt += dfs2(gchd, chd);
    }
    if (subTree[chd] == 0 && cnt == 1) {
        ok = true;
        // cout << "type 1: sub = 0 and contains one m, " << chd  << '\n';
    }
    if (cnt == 2) {
        ok = true;
        // cout << "type 2: sub contains two m, " << chd  << '\n';
    }
    return min(1, cnt + (subTree[chd] == xum));
}

void sol()
{
    cin >> n >> k;
    // wa
    xum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        xum ^= w[i];
        g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (xum == 0) {
        cout << "YES\n"; 
    } else if (k == 2) {
        cout << "NO\n";
    } else {
        // wa
        ok = false;
        dfs1(1, 0);
        dfs2(1, 0);
        cout << (ok ? "YES\n" : "NO\n");
    }
}
