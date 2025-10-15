void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> cnt;
    int maxv = -0x3f3f33f, minv = 0x3f3f3f3f;
    for (int& x : nums) {
        cin >> x;
        cnt[x]++;
        minv = min(minv, x);
        maxv = max(maxv, x);
    }
    if (maxv - minv < 2) {
        cout << n << endl;
        for (int x : nums) {
            cout << x << " ";
        }
        return;
    }
    int a = cnt[minv], b = cnt[minv + 1], c = cnt[minv + 2];
    if (a + c + b % 2 < b + abs(c - a)) {
        cout << a + c + b % 2 << endl;
        a += b / 2;
        c += b / 2;
        b %= 2;

        for (int i = 0; i < a; i++) {
            cout << minv << " ";
        }
        for (int i = 0; i < c; i++) {
            cout << minv + 2 << " ";
        }
        for (int i = 0; i < b; i++) {
            cout << minv + 1 << " ";
        }
    } else {
        cout << b + abs(c - a) << endl;
        b += min(a, c) * 2;
        int t = min(a, c);
        c -= t;
        a -= t;
        for (int i = 0; i < b; i++) {
            cout << minv + 1 << " ";
        }
        for (int i = 0; i < a; i++) {
            cout << minv << " ";
        }
        for (int i = 0; i < c; i++) {
            cout << minv + 2 << " ";
        }        
    }
}
