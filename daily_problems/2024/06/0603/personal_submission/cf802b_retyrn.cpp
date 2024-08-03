int n, k;

void solve() {
    cin >> n >> k;
    vector<queue<int>> q(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[i] = x;
        q[x].push(i);
    }
    
    vector<int> st(n + 1); // 是否买下
    set<int> S; // 下一个需要的日期
    int cnt = 0;
    
    int res = 0;
    for (int i = 0; i < n; i ++) {
        if (st[a[i]]) {
            S.erase(i);
            q[a[i]].pop();
            if (em(q[a[i]])) {
                st[a[i]] = false;
                cnt -= 1;
            }
            else S.insert(q[a[i]].front());
            continue;
        }
        if (cnt == k) {
            auto t = *S.rbegin();
            int who = a[t];
            S.erase(t);
            cnt -= 1;
            st[who] = false;
        }
        if (cnt < k) {
            res += 1;
            q[a[i]].pop();
            if (!em(q[a[i]])) {
                S.insert(q[a[i]].front());
                cnt += 1;
                st[a[i]] = true;
            }
        }
    }
    cout << res << endl;
}