int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    vector<int> cnt(n + 1);
    
    int j = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == b[j]) {
            j ++;
        }
        else cnt[a[i]] += 1;
        while (j < n and j - 1 >= 0 and b[j] == b[j - 1] and cnt[b[j]] > 0) {
            cnt[b[j]] --;
            j ++;
        }
    }
    cout << (j == n ? "YES" : "NO") << endl;
}