/*
考虑双指针
当所有的颜色的数量都至少达到要求之后，移动左指针，直到其变成最小的包含至少够的字符的区间
这个区间要删除的数量就可以算出来了
移动右指针，再移动左指针
*/

int n, m, a[N], k[N];
int cnt[N], useless_cnt = 0;

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> k[i];
    }

    int l = 1, r = 1;
    set<int> needs;
    for (int i = 1; i <= m; i++) {
        if (k[i] != 0)
            needs.insert(i);
    }
    for ( ; r <= n && needs.size() > 0; r++) {
        cnt[a[r]]++;
        if (cnt[a[r]] > k[a[r]]) {
            useless_cnt++;
        }
        if (cnt[a[r]] >= k[a[r]]) {
            needs.erase(a[r]);
        }
    }
    if (needs.size() > 0) {
        cout << "-1\n";
        return;
    }

    int res = n;
    bool first_round = true;
    r--;
    do {
        if (first_round) {
            first_round = false;
        } else {
            cnt[a[r]]++;
            if (cnt[a[r]] > k[a[r]]) {
                useless_cnt++;
            }
        }
        while (true) {
            if (cnt[a[l]] - 1 >= k[a[l]]) {
                cnt[a[l]]--;
                l++;
                useless_cnt--;
            } else {
                break;
            }
        }
        res = min(res, useless_cnt);
        r++;
    } while (r <= n);
    cout << res << "\n";
}   
