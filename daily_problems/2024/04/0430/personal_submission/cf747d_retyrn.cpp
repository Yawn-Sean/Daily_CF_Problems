int n, k;

int cal(priority_queue<int, vector<int>, greater<int>> q, int k) {
    int res = 0;
    while (!em(q)) {
        auto t = q.top();
        q.pop();
        if (k < t) break;
        k -= t;
        res += 1;
    }
    return res;
}
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] < 0) a[i] = -1;
        else a[i] = 1;
        if (a[i] < 0) cnt += 1;
    }
    
    if (cnt > k) {
        cout << -1 << endl;
        return;
    }
    if (cnt == 0) {
        cout << 0 << endl;
        return;
    }
    
    // 开头的1无所谓
    reverse(all(a));
    while (!em(a) and a.back() == 1) {
        a.pop_back();
    }
    reverse(all(a));
    n = sz(a);
    
    k -= cnt;
    cnt = 0;
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0, last = 1; i < n; i ++) {
        if (a[i] != last) sum ++, last = a[i];
        if (a[i] > 0) cnt ++;
        else {
            if (cnt > 0) q.push(cnt);
            cnt = 0;
        }
    }
    // 最后cnt如果>0 可以节省一次
    // 堆中的可以节省两次
    
    // 分别就要和不要最后一次进行讨论
    int res = sum - cal(q, k) * 2;
    
    if (cnt > 0 and k >= cnt) {
        res = min(res, sum - 1 - cal(q, k - cnt) * 2);
    }
    cout << res << endl;
}