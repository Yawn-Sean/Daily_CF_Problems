/*
p 输入中已经给出来了
要求输出的是 q 的个数，并升序输出 q
先把对 p 同余的数拿出来，然后就可以双指针了
*/

int a[N], b[N], n, m, p;

void meibao() {
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    vector<int> res(n + 1, 0);
    for (int st = 0; st < min(p, n); st++) {
        map<int, int> cur_cnt;
        int diff_cnt = cnt.size();
        for (int i = 0; i < m && st + i * p < n; i++) {
            int val = a[st + i * p];
            cur_cnt[val]++;
            if (!cnt.count(val)) {
                if (cur_cnt[val] == 1) {
                    diff_cnt++;
                }
            } else {
                if (cur_cnt[val] == cnt[val]) {
                    diff_cnt--;
                } else if (cur_cnt[val] == cnt[val] + 1) {
                    diff_cnt++;
                }
            }
        }

        if (diff_cnt == 0) {
            res[st + 1] = 1;
        }

        if (st + (LL)(m) * p >= n) {
            continue;
        }

        for (int i = m; st + i * p < n; i++) {
            int del_val = a[st + (i - m) * p];
            cur_cnt[del_val]--;
            if (!cnt.count(del_val)) {
                if (cur_cnt[del_val] == 0) {
                    diff_cnt--;
                }
            } else {
                if (cur_cnt[del_val] == cnt[del_val]) {
                    diff_cnt--;
                } else if (cur_cnt[del_val] == cnt[del_val] - 1) {
                    diff_cnt++;
                }
            }

            int val = a[st + i * p];
            cur_cnt[val]++;
            if (!cnt.count(val)) {
                if (cur_cnt[val] == 1) {
                    diff_cnt++;
                }
            } else {
                if (cur_cnt[val] == cnt[val]) {
                    diff_cnt--;
                } else if (cur_cnt[val] == cnt[val] + 1) {
                    diff_cnt++;
                }
            }

            if (diff_cnt == 0) {
                res[st + (i - m + 1) * p + 1] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (res[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        if (res[i]) {
            cout << i << " ";
        }
    }
}
