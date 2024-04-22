void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            char ch;
            cin >> ch;
            t[i][j] = (ch == 'B');
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        int l = n+1, r = 0, tol = 0;
        for (int j = 1; j <= n; j ++ ) {
            if (t[i][j]) {
                l = min(l, j);
                r = max(r, j);
                tol ++;
            }
        }
        if (!tol) {
            ans ++;
        } else if (r - l + 1 > k) continue;
        else {
            int x, y;
            x = max(1ll, i - k + 1), y = max(1ll, r - k + 1);
            a[i][l] ++; a[i][y-1] --; a[x-1][l] --;a[x-1][y-1] ++;
        }
    }

    for (int i = 1; i <= n; i ++ ) {
        int tol = 0, l = n+1, r = 0;
        for (int j = 1; j <= n; j ++ ) {
            if (t[j][i]) {
                l = min(l, j);
                r = max(r, j);
                tol ++;
            }
        }
        if (!tol) {
            ans ++;
        } else if (r - l + 1 > k) continue;
        else {
            int x, y;
            x = max(1ll, i - k + 1), y = max(1ll, r - k + 1);
            a[l][i] ++; a[l][x-1] --; a[y-1][i] --; a[y-1][x-1] ++;
        }
    }

    
    for (int i = n; i >= 1; i -- ) {
        for (int j = n; j >= 1; j -- ) {
            pre[i][j] = pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + a[i][j];
        }   
    }
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            res = max(res, ans + pre[i][j]);
        }
    }
    cout << res << endl;
} 