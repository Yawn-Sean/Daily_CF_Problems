/*
(值, 位置) 双关键字
每次看最小的两个，如果能合并则合并
最后按照顺序输出即可
*/

int T;
LL n, res[N];

void solve1() {
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        LL val;
        cin >> val;
        q.push({val, i});
    }

    int cnt = 0;
    while (q.size() >= 2) {
        PLL u = q.top();
        q.pop();
        PLL v = q.top();
        q.pop();
        if (u.x == v.x) {
            v.x += u.x;
            q.push(v);
        } else {
            res[u.y] = u.x;
            cnt++;
            q.push(v);
        }
    }

    if (!q.empty()) {
        res[q.top().y] = q.top().x;
        cnt++;
    }

    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (res[i] > 0) {
            cout << res[i] << " ";
        }
    }
}                                                                                                                  
