/*
构造 2^n 个 2^n 维向量，向量中每个分量的值只能是 1 或者 -1，使得两两正交
羊神提示：递推
已经有了 k 的时候的正交基，怎么构造 k + 1 时候的正交基
考虑从 A_k 的基础上拼出来 A_(k + 1)
A_k A_k
A_k A_k
前 k 行内随便选两行，或者后 k 行里随便选两行都可以，但是前 k 行和后 k 行各选一个就可能不行
把右下角那块取相反数即可
*/

int n;
int res[M][M];

void copy(int flag, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            int k = (i - x1) + x3;
            int l = (j - y1) + y3;
            res[k][l] = res[i][j] * flag;
        }
    }
}

void dfs(int k, int x1, int y1, int x2, int y2) {
    if (k == 1) {
        assert(x1 + 1 == x2);
        assert(y1 + 1 == y2);
        res[x1][y1] = 1;
        res[x1][y2] = 1;
        res[x2][y1] = 1;
        res[x2][y2] = -1;
        return;
    }
    int len = x2 - x1 + 1;
    int xmid = x1 + len / 2 - 1, ymid = y1 + len / 2 - 1;
    dfs(k - 1, x1, y1, xmid, ymid);
    copy(1, x1, y1, xmid, ymid, x1, ymid + 1, xmid, y2);
    copy(1, x1, y1, xmid, ymid, xmid + 1, y1, x2, ymid);
    copy(-1, x1, y1, xmid, ymid, xmid + 1, ymid + 1, x2, y2);
}

void meibao() {
    cin >> n;
    if (n == 0) {
        cout << "+\n";
        return;
    }
    dfs(n, 1, 1, (1 << n), (1 << n));
    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 1; j <= (1 << n); j++) {
            // cout << res[i][j];
            cout << (res[i][j] == 1 ? "+" : "*");
        }
        cout << "\n";
    }
}
