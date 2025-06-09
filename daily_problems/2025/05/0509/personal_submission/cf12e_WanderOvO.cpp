int n, grid[M][M];

void meibao() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            grid[i][j] = (i + j) % (n - 1) + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        grid[n - 1][i] = grid[i][i];
        grid[i][n - 1] = grid[i][i];
        grid[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}   
