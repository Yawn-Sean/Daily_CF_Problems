/*
把图建出来，是内向基环森林
每个基环树必须是一个环才行，不能有链，否则反向一定不成立，这要求输入必须是一个排列
对于偶数长度的环，需要走环 / 2 步的整数倍
对于奇数长度的环，必须走环长度的整数倍
*/

bool vis[N];
LL n, len, res;
vector<vector<int>> e(N);

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

void dfs(int u) {
    vis[u] = true;
    len++;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void meibao() {
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int ne;
        cin >> ne;
        e[i].push_back(ne);
        if (!vis[ne]) {
            vis[ne] = true;
        } else {
            ok = false;
        }
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        memset(vis, 0, sizeof vis);
        res = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                len = 0;
                dfs(i);
                if (len % 2 == 0) {
                    res = lcm(res, len / 2);
                } else {
                    res = lcm(res, len);
                }
            }
        }
        cout << res << "\n";
    }
}
