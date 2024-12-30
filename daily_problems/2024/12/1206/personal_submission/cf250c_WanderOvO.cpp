int n, k;
int a[N], res[N];

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    b.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] != b.back()) {
            b.push_back(a[i]);
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (i == 0 || i + 1 == b.size() || b[i - 1] != b[i + 1]) {
            res[b[i]]++;
        } else {
            res[b[i]] += 2;
        }
    }

    int mx = -INF, mxpos = -1;
    for (int i = 0; i <= k; i++) {
        if (mx < res[i]) {
            mx = res[i];
            mxpos = i;
        }
    }
    cout << mxpos << "\n";
}
