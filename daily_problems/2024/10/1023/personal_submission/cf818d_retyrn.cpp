int n, A;
int cnt[maxn];

void solve() {
    cin >> n >> A;
    vector<int> a(n);
    cin >> a;
    
    set<int> S;
    for (int i = 0; i < n; i ++) {
        S.insert(a[i]);
    }
    S.erase(A);
    
    for (auto x : a) {
        if (x != A) {
            cnt[x] += 1;
            continue;
        }
        cnt[A] ++;
        for (auto it = S.begin(); it != S.end(); ) {
            if (cnt[*it] < cnt[A]) it = S.erase(it);
            else it ++;
        }
        if (em(S)) break;
    }
    cout << (em(S) ? -1 : *S.begin()) << endl;
}