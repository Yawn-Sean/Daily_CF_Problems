void solve()
{
    int n, kk;
    cin >> n >> kk;
    vv(int, f, 4, 2 * n + 1);
    f[0][1] = 1;
    f[1][2] = 1;
    f[2][2] = 1;
    f[3][1] = 1;
    vector<vector<int>> g = {
        {0, 1, 1, 1},
        {0, 0, 2, 0},
        {0, 2, 0, 0},
        {1, 1, 1, 0}};
    vv(int, tf, 4, 2 * n + 1);
    fo(i, 1, n)
    {

        fo(j, 0, 4)
        {
            fo(k, 1, kk + 1)
            {
                if (f[j][k])
                    fo(tj, 0, 4)
                    {
                        int tk = k + g[j][tj];
                        tf[tj][tk] += f[j][k];
                        // f表示前i列最后一列为j情况（共4种情况）时形成k个连通块的方案数
                        // 更新最后一列的f值
                        tf[tj][tk] %= mod;
                    }
            }
        }
        fo(j, 0, 4)
        {
            fo(k, 1, kk + 1)
            {
                // debug(j, k, f[j][k]);
                f[j][k] = tf[j][k];
                tf[j][k] = 0;
            }
        }
    }
    int ans = 0;
    fo(j, 0, 4)
    {
        ans += f[j][kk];
        ans %= mod;
    }
    ca;
}
