/*
由于不能堵边界，所以最短路长度始终都是 2 * n - 2
首先发现，如果障碍物个数是偶数个，则总可以保证 YES，只要在中间两行每次填一列就好，上下对称
手玩发现其实左右对称也是可以的，因为一个是 (1, 1) 到 (4, n)，另一个看成是 (1, n) 到 (4, 1) 即可
*/

void meibao() {
    int n, k;
    cin >> n >> k;
    cout << "YES\n";
    vector<vector<char>> res(4, vector<char>(n, '.'));
    if (k % 2 == 0) {
        for (int i = 1; i < n && k > 0; i++) {  
            res[1][i] = '#';
            res[2][i] = '#';
            k -= 2;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << "\n";
        }
    } else {
        res[1][n / 2] = '#';
        k--;
        for (int i = 1; i < n / 2 && k > 0; i++) {
            res[1][i] = '#';
            res[1][n - i - 1] = '#';
            k -= 2;
        }
        for (int i = 1; i < n / 2 && k > 0; i++) {
            res[2][i] = '#';
            res[2][n - i - 1] = '#';
            k -= 2;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << "\n";
        }
    }
}
