int n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "1 1" << endl;
        return;
    }
    vector<int> a(n << 1);
    a[0] = a[n - 1] = 1;
    a[n] = a[n * 2 - 2] = 2;
    int l1 = 1, r1 = n - 2;
    int l2 = n + 1, r2 = n * 2 - 3;
    
    for (int i = 3; i < n; i ++) {
        if (i & 1) {
            a[l1] = a[r1] = i;
            l1 ++, r1 --;
        }
        else {
            a[l2] = a[r2] = i;
            l2 ++, r2 --;
        }
    }
    
    for (int i = 0; i < (n << 1); i ++) {
        if (!a[i]) a[i] = n;
    }
    cout << a << endl;
}