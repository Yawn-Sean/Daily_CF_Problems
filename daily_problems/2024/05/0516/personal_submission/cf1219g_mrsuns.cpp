struct zdj {
    int n, sum;
    zdj(int _n) :n(_n), sum(0) {}
    priority_queue<int, vector<int>, greater<int>> st;
    int get() {
        return sum;
    }
    void insert(int x) {
        st.push(x);sum += x;
        if (st.size() > n) {
            sum -= st.top();
            st.pop();
        }
    }
};

void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    int s = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) cin >> a[i][j], s += a[i][j];
    }
    vector<int> hang(n + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) hang[i] += a[i][j];
    }
    vector<int> lie(m + 1);
    for (int j = 1;j <= m;j++) {
        for (int i = 1;i <= n;i++) lie[j] += a[i][j];
    }
    if (n <= 4 || m <= 4) {
        cout << s << endl;
        return;
    }
    int res = 0;
    {
        zdj st(4);
        for (int i = 1;i <= n;i++) {
            st.insert(hang[i]);
        }
        res = max(res, st.get());
    }

    {
        zdj st(4);
        for (int i = 1;i <= m;i++) {
            st.insert(lie[i]);
        }
        res = max(res, st.get());
    }

    {
        for (int i = 1;i <= n;i++) {
            zdj st(3);
            for (int j = 1;j <= m;j++) {
                st.insert(lie[j] - a[i][j]);
            }
            res = max(res, st.get() + hang[i]);
        }
    }

    {
        for (int j = 1;j <= m;j++) {
            zdj st(3);
            for (int i = 1;i <= n;i++) {
                st.insert(hang[i] - a[i][j]);
            }
            res = max(res, st.get() + lie[j]);
        }
    }

    {
        if (n > m) {
            for (int i = 1;i <= n;i++) {
                for (int j = i + 1;j <= n;j++) {
                    zdj st(2);
                    for (int k = 1;k <= m;k++) {
                        st.insert(lie[k] - a[i][k] - a[j][k]);
                    }
                    res = max(res, st.get() + hang[i] + hang[j]);
                }
            }
        }
        else {
            for (int i = 1;i <= m;i++) {
                for (int j = i + 1;j <= m;j++) {
                    zdj st(2);
                    for (int k = 1;k <= n;k++) {
                        st.insert(hang[k] - a[k][i] - a[k][j]);
                    }
                    res = max(res, st.get() + lie[i] + lie[j]);
                }
            }
        }
    }
    cout << res << endl;
}
