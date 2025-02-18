int n, s;

void solve() {
    cin >> n >> s;
    s --;
    vector<int> a(n), cnt(n);
    cin >> a;
    int wrong = 0;
    for (int i = 0; i < n; i ++) {
        if (i == s) continue;
        int x = a[i];
        if (x == 0) wrong += 1;
        else cnt[x] += 1;
    }
    if (a[s] == 0) cnt[0] += 1;
    else wrong += 1;
    
    int need = 0;
    for (int i = 0; i < n; i ++) {
        if (cnt[i] == 0) need += 1;
    }
    if (wrong >= need) {
        cout << wrong << endl;
        return;
    }
    for (int i = n - 1; i >= 0; i --) {
        if (cnt[i] > 0) {
            if (wrong + cnt[i] < need) {
                wrong += cnt[i];
                continue;
            }
            cout << need << endl;
            break;
        }
        else {
            need -= 1;
            if (wrong >= need) {
                cout << wrong << endl;
                break;
            }
        }
    }
}