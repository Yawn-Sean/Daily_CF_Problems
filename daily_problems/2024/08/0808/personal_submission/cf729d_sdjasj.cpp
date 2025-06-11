void solve() {
    int n, a, k, b;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int l = 1, r = n;
    function<bool(int, bool)> check = [&](int x, bool flag) -> bool {
        int cnt = 0;
        for (int i = 0; i < n && cnt < x; i++) {
            if (s[i] == '1') continue;
            int j = i, pre = i;
            while (j < n && s[j] == '0' && cnt < x) {
                if (j - pre + 1 == b) {
                    s[j] = '2';
                    pre = j + 1;
                    cnt++;
                }
                j++;
            }
            i = j;
        }
        int cntBoat = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') continue;
            int j = i, pre = i;
            while (j < n && s[j] == '0') {
                if(j - pre + 1 == b) {
                    cntBoat++;
                    pre = j + 1;
                }
                j++;
            }
            i = j;
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '2') s[i] = '0';
            }
        }

        return cntBoat < a;
    };
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid, true)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    check(r, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            cout << i + 1 << " ";
        }
    }
}