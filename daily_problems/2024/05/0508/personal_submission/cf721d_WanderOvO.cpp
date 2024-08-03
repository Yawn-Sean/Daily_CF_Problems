/*
假如乘积原本就是负数，则只需要把当前绝对值最小的那个操作即可，k 不大，可以用堆
假如乘积原本是正数，则选一个绝对值最小的数，改变一下它的符号，然后和负数情况一样了
假如乘积原本是 0，则先考虑把 0 都变成 x 或者 -x，如果能，则变成负数的情况了，否则一定是 0
*/

int T;
LL n, k, x, a[N];

void solve1() {
    cin >> n >> k >> x;
    LL negcnt = 0;
    LL zerocnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        negcnt += (a[i] < 0 ? 1 : 0);
        zerocnt += (a[i] == 0 ? 1 : 0);
    }
    
    if (zerocnt > 0) {
        if (k < zerocnt) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            return;
        }
        
        // 转化为乘积是负数的情况
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                if (negcnt % 2 == 0) {
                    negcnt++;
                    a[i] -= x;
                } else {
                    a[i] += x;
                }
                k--;
            }
        }
    }
    
    if (negcnt % 2 == 0) {
        LL mn = 1e9 + 10, pos = 0;
        for (int i = 1; i <= n; i++) {
            LL d = abs(a[i]);
            if (mn > d) {
                mn = d;
                pos = i;
            }
        }
        
        if (mn < k * x) {
            // 能变成负数
            LL cnt = mn / x;
            while (mn - cnt * x >= 0) {
                cnt++;
            }
            cnt = min(cnt, k);
            a[pos] += (a[pos] >= 0 ? -1 : 1) * cnt * x;
            k -= cnt;
        } else {
            // 不能变成负数
            a[pos] += (a[pos] >= 0 ? -1 : 1) * k * x;
            k = 0;
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            return;
        }
    }
    
    // 已经是负数
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    for (int i = 1; i <= n; i++) {
        q.push({(a[i] > 0 ? a[i] : -a[i]), i});
    }
    for (int i = 1; i <= k; i++) {
        PLL u = q.top();
        q.pop();
        int pos = u.y;
        if (a[pos] < 0) {
            a[pos] -= x;
        } else {
            a[pos] += x;
        }
        u.x += x;
        q.push(u);
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}        