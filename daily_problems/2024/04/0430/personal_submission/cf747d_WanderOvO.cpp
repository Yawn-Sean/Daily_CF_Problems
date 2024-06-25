/*
< 0 时必须用雪地轮胎
如果 < 0 的数的个数 > k，则无解
否则，至少可以每次遇到一段连续的雪天前换成雪地轮胎，走完之后换成普通轮胎
为了减少交换次数，需要看能把哪些不连续的雪天段连接起来，都用雪地轮胎走
两个不相邻的雪天段连接起来，能减少两次轮胎替换；而如果是最后一段是非雪天，则不换轮胎能减少 1 次
我们想尽可能多地连接段，就得尽可能选非雪天段短的作为桥梁
先把所有雪天必须用的轮胎天数减去，并且强制每次遇到/离开雪天都要换轮胎
然后每次拿一个没取过的最小的非雪天段，如果能换则换
对于最后一段不是雪天的情况，我们可以把换或者不换这两种方案都算一下，取较小的
*/

int T;
int n, k, a[N];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if ( (a[i - 1] >= 0 && a[i] < 0) || (a[i - 1] < 0 && a[i] >= 0) ) {
            res++;
        }        
        if (a[i] < 0) {
            k--;
        }
    }
    if (k < 0) {
        cout << "-1\n";
        return;
    }
    
    int st = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            st = i;
            break;
        }
    }
    
    if (st == n + 1) {
        cout << "0\n";
        return;
    }
    
    int cnt = 1;
    vector<int> b;
    for (int i = st + 1; i <= n; i++) {
        if ( (a[i - 1] >= 0 && a[i] < 0) || (a[i - 1] < 0 && a[i] >= 0) ) {
            b.pb(cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    int kk = k;
    if (a[n] < 0) {
        b.pb(cnt);
    }
    // 不考虑最后一段
    int res1 = res, res2 = res;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i < b.size(); i += 2) {
        q.push(b[i]);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (kk >= u) {
            kk -= u;
            res1 -= 2;
        }
    }
    
    if (a[n] >= 0) {
        kk = k;
        if (kk >= cnt) {
            kk -= cnt;
            res2--;
        }
        for (int i = 1; i < b.size(); i += 2) {
            q.push(b[i]);
        }
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (kk >= u) {
                kk -= u;
                res2 -= 2;
            }
        }
    }
    res = min(res1, res2);
    cout << res << "\n";
}                  