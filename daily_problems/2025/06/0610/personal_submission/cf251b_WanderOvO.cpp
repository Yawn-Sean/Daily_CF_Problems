/*
两种操作：
1. p[i] = p[q[i]]
2. p[q[i]] = p[i]
一共 k 次操作，最后把 p 变成 s
两个操作互为逆操作
数据范围很小，只有 100
事实上，可以枚举第一种操作执行了多少次，然后暴力模拟整个过程
假设第一种操作执行了 i 次，则第二种操作执行了 k - i 次
净看就是第一种操作执行了 2 * i - k 次
我们还关心会不会中间就到了某个目标，导致不符合题意
可以先计算一下两种操作分别最少几步能到目标(k 步以内)
假设正着走至少 min_cnt 步会变成目标，则假如净走的步数超过了这个，肯定就救不过来了
一开始就相等怎么办？特判掉
折返可能不小心折返到另一个方向相等，也得特判
*/

int q[M], s[M], n, k;

void meibao() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int min_cnt = k + 1, rev_min_cnt = k + 1;
    int cur[M], ne[M];
    for (int i = 1; i <= n; i++) {
        cur[i] = i;
    }

    auto same = [&] () -> bool {
        bool res = true;
        for (int i = 1; i <= n; i++) {
            res &= (cur[i] == s[i]);
        }
        return res;
    };

    // 一开始就相等，k >= 1，肯定不行
    if (same()) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            ne[j] = cur[q[j]];
        }
        for (int j = 1; j <= n; j++) {
            cur[j] = ne[j];
        }
        if (same()) {
            min_cnt = i;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cur[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            ne[q[j]] = cur[j];
        }
        for (int j = 1; j <= n; j++) {
            cur[j] = ne[j];
        }
        if (same()) {
            rev_min_cnt = i;
            break;
        }
    }

    // 特判只用某个操作
    if (min_cnt == k || rev_min_cnt == k) {
        cout << "YES\n";
        return;
    }

    // 必须来回折返的
    bool ok = false;
    for (int i = 1; i < k; i++) {
        int cnt = 2 * i - k;
        if (cnt >= 0) {
            if (cnt == min_cnt) {
                if (cnt - 2 != -rev_min_cnt) {
                    ok = true;
                }
            }
        } else {
            cnt = -cnt;
            if (cnt == rev_min_cnt) {
                if (cnt - 2 != -min_cnt) {
                    ok = true;
                }
            } 
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";
}
