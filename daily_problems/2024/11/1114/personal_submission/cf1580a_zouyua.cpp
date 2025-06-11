void solve()
{
    int n, m; cin >> n >> m;
    vector g(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            char c; cin >> c;
            g[i][j] = c - '0';
        }
    }
    auto pre = g;
    for(int i = 1; i <= n ;i ++) 
        for(int j = 1; j <= m; j ++) 
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + pre[i][j] - pre[i - 1][j - 1];
    int res = n * m;
    vector<int> f(m + 1);
    auto gets = [&](int l1, int r1, int l2, int r2) {
        return pre[l2][r2] - pre[l2][r1 - 1] - pre[l1 - 1][r2] + pre[l1 - 1][r1 - 1];
    };
    for(int i = 1; i < n; i ++) {
        for(int j = i + 4; j <= n; j ++) {
            for(int k = 4; k <= m; k ++) {//上下边界确定后的1~k的贡献，后用前缀和可以快速求得矩阵的答案
                f[k] = gets(i + 1, 1, j - 1, k - 1)  //中间1变0的需要的操作
                       + (k - 1) * 2 - gets(i, 1, i, k - 1) - gets(j, 1, j, k - 1)//上下变1需要的
                       + j - i - 1 - gets(i + 1, k, j - 1, k);//右边需要的，只有右边界需要
            }
            for(int k = m - 1; k >= 4; k --) {//后缀最小值
                f[k] = min(f[k], f[k + 1]);
            }
            for(int k = 1; k + 3 <= m; k ++) {
                int t = f[k + 3] -
                                (gets(i + 1, 1, j - 1, k)  //只需要k+1的贡献，所以把k算上
                                 + k * 2 - gets(i, 1, i, k) - gets(j, 1, j, k))//上下边界也是需要的是k+1的所以也到k
                                 + (j - i - 1) - gets(i + 1, k, j - 1, k);//上面没算左边界的贡献，只是方形加右边界
                res = min(res, t);
            }
        }
    }
    cout << res << endl;
}
