void solve()
{
    int n; cin >> n;
    if(n == 0) {
        cout << '+' << endl;
        return ;
    }
    vector<vector<int>> g(1 << n, vector<int> (1 << n));
    g[0][0] = 1, g[0][1] = 1, g[1][0] = 1, g[1][1] = 0;
    for(int k = 2; k <= n; k ++) {
        for(int i = 0; i < (1 << (k - 1)); i ++) {
            for(int j = 0; j < (1 << (k - 1)); j ++) {
                g[i][(1 << (k - 1)) + j] = g[i][j]; 
            }
        }
        for(int i = 0; i < (1 << (k - 1)); i ++) {
            for(int j = 0; j < (1 << (k - 1)); j ++) {
                g[(1 << (k - 1)) + i][j] = g[i][j]; 
            }
        }
        for(int i = 0; i < (1 << (k - 1)); i ++) {
            for(int j = 0; j < (1 << (k - 1)); j ++) {
                g[(1 << (k - 1)) + i][(1 << (k - 1)) + j] = g[i][j]; 
            }
        }
        for(int i = 1 << (k - 1); i < 1 << k; i ++) {
            for(int j = 1 << (k - 1); j < 1 << k; j ++) {
                g[i][j] = !g[i][j];
            }
        }
    }
    for(int i = 0; i < 1 << n; i ++) {
        for(int j = 0; j < 1 << n; j ++) {
            cout << (g[i][j] ? '+' : '*');
        }
        cout << endl;
    }
}
