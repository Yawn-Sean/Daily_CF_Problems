int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (n == 1) {
        cout << "Alice" << endl;
        return;
    }
    vector<int> A = {a[0]}, B = {a[n - 1]};
    for (int i = 1; i < n; i ++) {
        if (a[i] > a[i - 1]) A.pbk(a[i]);
        else break;
    }
    for (int i = n - 2; i >= 0; i --) {
        if (a[i] > a[i + 1]) B.pbk(a[i]);
        else break;
    }
    
    reverse(all(B));
    
    if (sz(A) % 2 and sz(B) % 2) {
        cout << "Alice" << endl;
        return;
    }

    if (sz(A) % 2 or sz(B) % 2) {
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}