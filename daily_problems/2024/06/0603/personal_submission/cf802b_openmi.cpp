void solve() {
    int n, k;
    cin >> n >> k;
    int x;
    vi borrow(n), nxt(n), last(n, n), has(n);
    rep (i, 0, n) {
        cin >> x;
        borrow[i] = x - 1;
    }
    br (i, n-1, 0) {
        nxt[i] = last[borrow[i]];
        last[borrow[i]] = i;
    }
    priority_queue<ll> pq;
    int ans = 0, cnt = 0;
    rep (i, 0, n) {
        while (pq.size() and !has[pq.top() % n]) {
            pq.pop();
        }
        if (!has[borrow[i]]) {
            if (cnt == k) {
                has[pq.top() % n] = 0;
                cnt--;
            }
            has[borrow[i]] = 1;
            cnt ++;
            ans ++;
        }
        pq.push(1LL * nxt[i] * n + borrow[i]);
    }
    cout << ans << nl; 

}
