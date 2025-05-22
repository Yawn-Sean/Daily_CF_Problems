/*
至多有 22 个数位要考虑，每个数位有 7 种填法
显然答案不会超过 1e18
考虑到需要补 0，所以要么小时补 0，要么分钟补 0，不能同时填不够位数
并且，只能补 1 位 0
如果强制小时补 0，则小时的剩下的位填起来就没限制了，直接上全排列
注意到只有 7 种数可以填，所以 n, m 特别大的时候一定无解
发现只要考虑 7 位数就好了，而 7 位的 7 进制数不超过 1e6 个，完全可以暴力枚举然后检查
*/

LL n, m, val[M], cnt1, cnt2, res = 0;
bool vis[M];

int get_cnt(LL val) {
    if (val == 0) {
        return 1;
    }

    int res = 0;
    while (val) {
        res++;
        val /= 7;
    }
    return res;
}

void dfs(int u) {
    if (u == cnt1 + cnt2 + 1) {
        int val1 = 0, val2 = 0;
        for (int i = 1; i <= cnt1; i++) {
            val1 = 7 * val1 + val[i];
        }
        for (int i = cnt1 + 1; i < u; i++) {
            val2 = 7 * val2 + val[i];
        }
        if (val1 < n && val2 < m) {
            res++;
            // for (int i = 1; i < u; i++) {
            //     cout << val[i];
            // }
            // cout << "\n";
        }
        return;
    }

    for (int i = 0; i < 7; i++) {
        if (!vis[i]) {
            val[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}
 
void meibao() {
    cin >> n >> m;
    cnt1 = get_cnt(n - 1), cnt2 = get_cnt(m - 1);
    if (cnt1 + cnt2 > 7) {
        cout << "0\n";
        return;
    }
    
    dfs(1);

    cout << res << "\n";
}    
