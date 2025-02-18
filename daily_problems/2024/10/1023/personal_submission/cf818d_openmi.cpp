void solve() {
    int n, A;
    cin >> n >> A;
    vi cs(n);
    in(cs);
    map<int, int> cnt;
    set<int> S;
    int f = 1;
    for (int c: cs) {
        if (f or S.contains(c) or c == A) {
            if (c != A) S.insert(c);
            cnt[c]++;
        }
        if (c == A) {
            vector<int> del;
            for (int oc: S) {
                if (cnt[oc] < cnt[A]) del.push_back(oc);
            }
            for (int i: del) S.erase(i);
            if (S.empty()) break;
            f = 0;
        }
    }
    if (S.empty()) cout << -1;
    else cout << *S.begin() << endl;
}
