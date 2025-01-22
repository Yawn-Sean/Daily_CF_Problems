/*
二分时间，施加操作，检查结果
*/

struct Operation {
    int x, y, t;
};

int n, m, k, q;
vector<Operation> ops;
int s[M][M];

bool check(int ans) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = 0;
        }
    }
    for (int i = 0; i < q; i++) {
        if (ops[i].t <= ans) {
            s[ops[i].x][ops[i].y]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            int x = i + k - 1, y = j + k - 1;
            if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == k * k) {
                return true;
            }
        }
    }
    return false;
}

void meibao() {
    cin >> n >> m >> k >> q;
    ops.clear();
    for (int i = 1; i <= q; i++) {
        int x, y, time;
        cin >> x >> y >> time;
        ops.push_back({x, y, time});
    }
    int l = 0, r = INF, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else if (check(r)) {
        cout << r << "\n";
    } else {
        cout << "-1\n";
    }
}
