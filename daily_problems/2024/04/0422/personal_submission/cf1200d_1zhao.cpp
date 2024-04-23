void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> mat(n);
    for(int i=0; i<n; i++) cin >> mat[i];

    vector<vector<int>> D(n+1, vector<int>(n+1));

    // row
    for(int i=0; i<n; i++) {
        int first = -1, last = -1;
        for(int j=0; j<n; j++) {
            if(mat[i][j] == 'B') {
                last = j;
                if(first == -1) first = j;
            }
        }
        if(first == -1) {
            D[0][0] ++;
            D[n][n] ++;
            D[0][n] --;
            D[n][0] --;
        } else if(last - first + 1 <= k) {
            int top = max(0, i-k+1);
            int bottom = i;
            int left = max(0, last-k+1);
            int right = first;
            // cout << top << ' ' << bottom << ' ' << left << ' ' << right << endl;
            D[top][left] ++;
            D[bottom+1][right+1] ++;
            D[top][right+1] --;
            D[bottom+1][left] --;
        }
    }

    // col
    for(int i=0; i<n; i++) {
        int first = -1, last = -1;
        for(int j=0; j<n; j++) {
            if(mat[j][i] == 'B') {
                last = j;
                if(first == -1) first = j;
            }
        }
        if(first == -1) {
            D[0][0] ++;
            D[n][n] ++;
            D[0][n] --;
            D[n][0] --;
        } else if(last - first + 1 <= k) {
            int left = max(0, i-k+1);
            int right = i;
            int top = max(0, last-k+1);
            int bottom = first;
            // cout << top << ' ' << bottom << ' ' << left << ' ' << right << endl;
            D[top][left] ++;
            D[bottom+1][right+1] ++;
            D[top][right+1] --;
            D[bottom+1][left] --;
        }
    }

    int res = 0;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            int t = D[i][j];
            if(i>0) {
                t+=D[i-1][j];
            }
            if(j>0) {                
                t+=D[i][j-1];
            }
            if(i>0 && j>0) {
                t-=D[i-1][j-1];
            }
            D[i][j] = t;
            res = max(res, t);
        }
    }
    cout << res << endl;

}
