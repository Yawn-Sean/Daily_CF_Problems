 
void solve() {
    int n;
    std::cin >> n;
    std::vector a(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }
 
    Fenwik2D S[4] = {Fenwik2D(n, n), Fenwik2D(n, n), Fenwik2D(n, n), Fenwik2D(n, n)};
    std::vector<std::vector<int>> l(n + 1, std::vector<int>(n + 1)), 
    r(n + 1, std::vector<int>(n + 1)),
    up(n + 1, std::vector<int>(n + 1)),
    down(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            l[i][j] = r[i][j] = j;
            up[i][j] = down[i][j] = i;
            if (a[i][j] == 1) {
                if (j > 1 && a[i][j - 1]) l[i][j] = l[i][j - 1];
                if (i > 1 && a[i - 1][j]) up[i][j] = up[i - 1][j];
            }
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (a[i][j] == 1) {
                if (j + 1 <= n && a[i][j + 1]) r[i][j] = r[i][j + 1];
                if (i + 1 <= n && a[i + 1][j]) down[i][j] = down[i + 1][j];   
            }
        }
    }
 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        Fenwicktree<> s(n);
        std::vector<std::pair<int, int>>q1,q2;
        i64 tmp1 = 0, tmp2 = 0;
        for (int j = 1, ii = i; ii <= n; j++, ii++) {
            if (a[j][ii]) {
                // ans++;
                tmp2++;
                int v1 = std::min(-l[j][ii] + ii, - up[j][ii] + j);
                int v2 = std::min(r[j][ii] - ii, down[j][ii] - j);
                q2.push_back({j, j + v2});
                q1.push_back({j - v1, j});
            }
        }
        int i1 = 0, i2 = 0;
        std::sort(q1.begin(), q1.end(), [](auto x, auto y) {
            return x.first < y.first;
        });
        std::sort(q2.begin(), q2.end(), [](auto x, auto y) {
            return x.first < y.first;
        });
        while (i2 < q2.size()) {
            while (i1 < q1.size() && q1[i1].first <= q2[i2].first) {
                s.add(q1[i1].second, 1);
                i1++;
            }
            tmp1 += s.quiry(q2[i2].second);
            i2++;
        }
        ans += tmp1 - tmp2 * (tmp2 - 1) / 2;
    }
    for (int j = 2; j <= n; j++) {
        Fenwicktree<> s(n);
        std::vector<std::pair<int, int>>q1,q2;
        i64 tmp1 = 0, tmp2 = 0;
        for (int i = 1, jj = j; jj <= n; jj++, i++) {
            if (a[jj][i]) {
                // ans++;
                tmp2++;
                int v1 = std::min(-l[jj][i] + i, - up[jj][i] + jj);
                int v2 = std::min(r[jj][i] - i, down[jj][i] - jj);
                q2.push_back({i, i + v2});
                q1.push_back({i - v1, i});
            }
        }
        int i1 = 0, i2 = 0;
        std::sort(q1.begin(), q1.end(), [](auto x, auto y) {
            return x.first < y.first;
        });
        std::sort(q2.begin(), q2.end(), [](auto x, auto y) {
            return x.first < y.first;
        });
        while (i2 < q2.size()) {
            while (i1 < q1.size() && q1[i1].first <= q2[i2].first) {
                s.add(q1[i1].second, 1);
                i1++;
            }
            tmp1 += s.quiry(q2[i2].second);
            i2++;
        }
        ans += tmp1 - tmp2 * (tmp2 - 1) / 2;
    }
    std::cout << ans;
}
