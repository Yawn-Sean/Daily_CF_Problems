int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    set<pii> segs;
    priority_queue<pii> q;
    
    int last = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] != a[last]) {
            segs.insert(mpr(last, i - last));
            q.push(mpr(i - last, -last));
            last = i;
        }
    }
    segs.insert(mpr(last, n - last));
    q.push(mpr(n - last, -last));
    
    int res = 0;
    while (sz(q)) {
        int len = q.top().fi, start = -q.top().se;
        q.pop();
        auto it = segs.find(mpr(start, len));
        if (it == segs.end()) {
            continue;
        }
        res += 1;
        it = segs.erase(it);
        if (em(segs) or it == segs.begin() or it == segs.end()) continue;
        auto it1 = it;
        it1 --;
        int s1 = it1->fi, s2 = it->fi, len1 = it1->se, len2 = it->se;
        if (a[s1] == a[s2]) {
            segs.erase(mpr(s1, len1));
            segs.erase(mpr(s2, len2));
            segs.insert(mpr(s1, len1 + len2));
            q.push(mpr(len1 + len2, -s1));
        }
    }
    
    cout << res << endl;
}