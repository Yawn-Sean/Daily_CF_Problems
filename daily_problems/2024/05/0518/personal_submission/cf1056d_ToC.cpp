// https://codeforces.com/contest/1056/submission/261538531
vector<int> g[MAXN];
int cnt[MAXN];
int leafc, idx;
int res[MAXN];
int dfs(int chd, int par) {
    int tmp = 0;
    for (auto &gchd : g[chd]) {
        if (gchd == par) continue;
        tmp += dfs(gchd, chd);
    }
    if (tmp == 0) {tmp = 1; leafc++;}
    cnt[idx++] = tmp;
    return tmp;
}
void sol()
{   
    cin >> n;
    int chd;
    for (int i = 2; i <= n; i++) {
        cin >> chd;
        g[i].push_back(chd);
        g[chd].push_back(i);
    }
    dfs(1, -1);
    sort(cnt, cnt + idx);
    for (int i = 0; i < idx; i++)
        cout << cnt[i] << " ";
    cout << '\n';
}
