int n;

void solve() {
    cin >> n;
    vector<int> a(n), p(n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    
    vector<int> f(n + 1);
    // f[i] 从标号为i的格子开始跳 先手的胜负
    
    for (int ai = n; ai >= 1; ai --) {
        int ans = -1;
        for (int j = p[ai] + ai; j < n; j += ai) {
            if (a[j] > ai) {
                if (f[a[j]] == -1) ans = 1;
            }
        }
        for (int j = p[ai] - ai; j >= 0; j -= ai) {
            if (a[j] > ai) {
                if (f[a[j]] == -1) ans = 1;
            }
        }
        f[ai] = ans;
    }
    string res;
    for (int i = 0; i < n; i ++) {
        res += (f[a[i]] > 0 ? 'A' : 'B');
    }
    cout << res << endl;
}