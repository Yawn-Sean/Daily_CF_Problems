/*
把转移关系建图，则相当于 x 走 k 步和走 2 * k 步到达的点一样
建出来的图是内向基环森林，所以走 k 步一定要走到环里面去，走 2 * k 步一定要回到 k 步的位置
所以 k 应该是环的大小的倍数，而环的大小可以求出来的
看每个点走多少步能走到环里，则 k 至少是最大的那个数，而 k 又得是环的大小的倍数，这需要我们把所有环大小取 lcm
然后看 k 取多少倍的 lcm
*/

LL cnt[M], f[M], d[M], vis[M], n;
vector<vector<int>> e(M);

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

void calc_cnt(int u, int c) {
    cnt[u] = c;
    for (auto v : e[u]) {
        if (d[v] == 0) {
            calc_cnt(v, c + 1);
        }
    }
}

LL calc_loop_size(int u, int sz) {
    bool cannot_move = true;
    vis[u] = 1;
    LL res = 0;
    for (auto v : e[u]) {
        if (d[v] != 0 && !vis[v]) {
            res = calc_loop_size(v, sz + 1);
            cannot_move = false;
        }
    }
    if (cannot_move) {
        res = sz;
    }
    return res;
}
 
void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        e[i].push_back(f[i]);
        d[f[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }

    LL loop_size_lcm = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] != 0 && !vis[i]) {
            loop_size_lcm = lcm(loop_size_lcm, calc_loop_size(i, 1));
        }
    }

    LL max_cnt = 0;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        LL c = 0;
        while (d[cur] == 0) {
            cur = f[cur];
            c++;
        }
        max_cnt = max(max_cnt, c);
    }

    LL res = (max_cnt + loop_size_lcm - 1) / loop_size_lcm * loop_size_lcm;
    if (res == 0) {
        res = loop_size_lcm;
    }
    cout << res << '\n';
}
