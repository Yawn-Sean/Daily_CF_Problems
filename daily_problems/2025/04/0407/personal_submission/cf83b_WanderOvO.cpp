/*
直观上来讲，应该是最大的那些留下了
假如 val 留下了，那么 val + 1 会不会被淘汰了呢？一定不会
假如有两个数都是 val，则如果原始顺序在右边的那个淘汰了，左边那个也一定淘汰了
对所有数双关键字排序，然后二分看看能剩下多长的后缀
最后还要考虑这些数最后的顺序如何
能否知道最后一次是减的谁？知道的话剩下顺序的只要转一圈就知道了
二分在排序数组中最后剩下的第一个数的下标，然后 check 是否可行
假设最后从 [pos, n] 都能剩下，则先把 1-pos - 1 给删了，并且要恰好删掉第 pos - 1 个数
在剩下的数中，找到最小的下标比 pos - 1 大的那个数，这个就是剩下元素的队头，如果没有更大的，就是最小的
最后用剩下的次数看最终队头是谁即可
*/

PLL a[N], b[N];
LL n, k;

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
        a[i].y = i;
    }

    sort(a + 1, a + n + 1);

    auto check = [&] (int ans) -> bool {
        LL op_cnt = 0, round_cnt = 0;
        for (int i = 1; i <= n; i++) {
            b[i] = a[i];
        }
        for (int i = 1; i < ans; i++) {
            if (i == ans - 1) {
                b[i].x -= round_cnt;
                round_cnt += b[i].x - 1;
                op_cnt += (b[i].x - 1) * (n - i + 1);
                for (int j = i; j <= n; j++) {
                    if (b[j].y <= b[i].y) {
                        op_cnt++;
                    }
                }
            } else {
                b[i].x -= round_cnt;    
                round_cnt += b[i].x;
                op_cnt += b[i].x * (n - i + 1);
            } 
        }
        return op_cnt <= k;
    };

    int l = 1, r = n + 1, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    int pos = check(r) ? r : l;
    // if (pos == n + 1) {
    //     cout << "-1\n";
    //     return;
    // }

    // cout << n - pos + 1 << "\n";
    // [1, pos - 1] 都没了，[1, pos - 2] 肯定都是轮次拉满的
    LL op_cnt = 0, round_cnt = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    for (int i = 1; i < pos; i++) {
        if (i == pos - 1) {
            b[i].x -= round_cnt;
            round_cnt += b[i].x - 1;
            op_cnt += (b[i].x - 1) * (n - i + 1);
            for (int j = i; j <= n; j++) {
                if (b[j].y <= b[i].y) {
                    op_cnt++;
                }
            }
        } else {
            b[i].x -= round_cnt;    
            round_cnt += b[i].x;
            op_cnt += b[i].x * (n - i + 1);
        } 
    }

    if (op_cnt < k && pos == n + 1) {
        cout << "-1\n";
    }

    // 至此，该删的都删了，只需要排剩下的数的顺序即可
    sort(b + pos, b + n + 1, [&] (PLL &o1, PLL &o2) -> bool {
        return o1.y < o2.y;
    });

    int first_pos = pos;
    int last_delele_id = (pos - 1 > 0 ? b[pos - 1].y : 0);
    for (int i = pos; i <= n; i++) {
        if (b[i].y > last_delele_id) {
            first_pos = i;
            break;
        }
    }

    vector<int> ps;
    for (int i = first_pos; i <= n; i++) {
        ps.push_back(b[i].y);
    }
    for (int i = pos; i < first_pos; i++) {
        ps.push_back(b[i].y);
    }

    // for (auto val : ps) {
    //     cout << val << " ";
    // }
    // cout << "\n";

    if (ps.size() == 0) {
        return;
    }

    LL left_cnt = k - op_cnt;
    // cout << left_cnt << "\n";
    first_pos = left_cnt % ps.size();
    for (int i = first_pos; i < ps.size(); i++) {
        cout << ps[i] << " ";
    }
    for (int i = 0; i < first_pos; i++) {
        cout << ps[i] << " ";
    }
}
