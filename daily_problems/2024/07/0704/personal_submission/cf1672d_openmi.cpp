void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, int> cnt, taken;
    rep (i, 0, n) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    in(b);
    int i, j;
    for (i = j = n - 1; i >= 0 and j >= 0; --i, --j)  {
        if (a[i] != b[j]) {
            if (j < n - 1 and b[j] == b[j + 1]) {
                if (cnt.count(b[j])) {
                    cnt[b[j]]--, taken[b[j]]++, ++i;
                    if (cnt[b[j]] == 0) cnt.erase(b[j]);
                } else if (taken[a[i]] > 0) {
                    taken[a[i]]--, ++j;
                } else {
                    return p(0), void(0);
                }
            } else if (taken[a[i]] > 0) {
                taken[a[i]]--, ++j;
            } else return p(0), void(0);
        } else {
            cnt[a[i]] --;
            if (cnt[b[j]] == 0) cnt.erase(b[j]);
        }

    }
    while (i >= 0) {
        if (taken[a[i]] > 0) taken[a[i]] --, --i;
        else return p(0), void(0);
    }
    if (i != -1 or j != -1 or cnt.size()) p(0);
    else p(1);
}
