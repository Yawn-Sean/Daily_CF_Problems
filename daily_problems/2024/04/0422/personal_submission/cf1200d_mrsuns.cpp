void Solve() {
    int n, k;cin >> n >> k;
    vector<string> s(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    vector<vector<int>> df(n + 2, vector<int>(n + 2));
    //[1,n-k+1],[1,n-k+1]
    int res = 0;
    for (int i = 1;i <= n;i++) {
        int ptr1 = -1, ptr2 = -1;
        for (int j = 1;j <= n;j++) {
            if (s[i][j] == 'B') {
                if (ptr1 == -1) ptr1 = j;
                ptr2 = j;
            }
        }
        if (ptr2 == -1) {
            res += 1;
        }
        else {
            int d = ptr2 - ptr1 + 1;
            if (d > k) continue;
            int x1 = max(1, i - k + 1);
            int y1 = max(1, ptr2 - k + 1);

            int x2 = min(n - k + 1, i);
            int y2 = min(n - k + 1, ptr1);

            df[x1][y1] += 1;
            df[x2 + 1][y1] -= 1;
            df[x1][y2 + 1] -= 1;
            df[x2 + 1][y2 + 1] += 1;
        }
    }

    for (int j = 1;j <= n;j++) {
        int ptr1 = -1, ptr2 = -1;
        for (int i = 1;i <= n;i++) {
            if (s[i][j] == 'B') {
                if (ptr1 == -1) ptr1 = i;
                ptr2 = i;
            }
        }
        if (ptr2 == -1) {
            res += 1;
        }
        else {
            int d = ptr2 - ptr1 + 1;
            if (d > k) continue;
            int y1 = max(1, j - k + 1);
            int x1 = max(1, ptr2 - k + 1);

            int y2 = min(n - k + 1, j);
            int x2 = min(n - k + 1, ptr1);

            df[x1][y1] += 1;
            df[x2 + 1][y1] -= 1;
            df[x1][y2 + 1] -= 1;
            df[x2 + 1][y2 + 1] += 1;
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            df[i][j] += df[i][j - 1];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            df[i][j] += df[i - 1][j];
        }
    }
    int mx = 0;
    for (int i = 1;i <= n - k + 1;i++) {
        for (int j = 1;j <= n - k + 1;j++) {
            mx = max(mx, df[i][j]);
        }
    }

    cout << mx + res << endl;


}
