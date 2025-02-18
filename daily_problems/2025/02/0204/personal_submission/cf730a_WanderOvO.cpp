/*
目标是让所有数相等
目前可以进行的操作是，选择 [2, min(5, n)] 个人，让他们的 rating -= 1
减到 0 的不会变成负数
一定存在把所有人变成 0 的方案，把所有人变成 0 至多是总共减 1e4，就算是一对一对搞都可以搞定
[2, min(5, n)] 带来了什么样的限制？意味着我们不能单独操作一个人的 rating
假设最终大家的 rating 都是 r，考虑最大的 a[i] - r
假如最大的 a[i] - r 比剩下所有的 a[j] - r 的和都大，则一定搞定不了
最终的 r 越大，越容易出现上面这种无解的情况，是单调的
倘若最终的 r 不会导致上述情况了，怎么办
每次配一对去搞，万一最后有没搞完的，就往前面塞一下，这需要我们保存下来前面的答案
*/

int a[N], n;
vector<vector<int>> res;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int target_r = 100;
    for (int i = 1; i <= n; i++) {
        target_r = min(target_r, a[i]);
    }
    for ( ; target_r >= 0; target_r--) {
        int sum = 0, mx = 0;
        for (int i = 1; i <= n; i++) {
            sum += a[i] - target_r;
            mx = max(mx, a[i] - target_r);
        }
        sum -= mx;
        if (sum >= mx) {
            break;
        }
    }
    if (target_r >= 0) {
        priority_queue<PII> pq;
        for (int i = 1; i <= n; i++) {
            if (a[i] - target_r != 0) {
                pq.push({a[i] - target_r, i});
            }
        }
        while (pq.size() > 1) {
            PII u = pq.top();
            pq.pop();
            PII v = pq.top();
            pq.pop();
            vector<int> group(n, 0);
            group[u.y - 1]++;
            group[v.y - 1]++;
            u.x--;
            v.x--;
            if (u.x > 0) {
                pq.push(u);
            }
            if (v.x > 0) {
                pq.push(v);
            }
            res.push_back(group);
        }
        if (pq.size() == 1) {
            PII u = pq.top();
            pq.pop();
            for (int i = 0; i < res.size() && u.x > 0; i++) {
                if (res[i][u.y - 1] == 0) {
                    res[i][u.y - 1]++;
                    u.x--;
                }
            }
            assert(u.x == 0);
        }
    } else {
        // 只能变成 0
        target_r = 0;
        for (int i = 1; i <= n; i += 5) {
            for (int cnt = 1; cnt <= 100; cnt++) {
                vector<int> group(n, 0);
                for (int j = i; j <= min(i + 4, n); j++) {
                    group[j - 1] = 1;
                }
                res.push_back(group);
            }
        }
    }
    cout << target_r << "\n";
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
