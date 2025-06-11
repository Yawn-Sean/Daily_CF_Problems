/*
对于 b[1]，其一定是 a[1] + ... + a[i]
对于 b[2]，其一定是 a[i + 1] + ... + a[j]
那么这一段真的能合并起来吗？考虑 [l, r] 段中的最大元素
假设最大元素周围还都是和自己相等的最大元素，则不可合并，也就是说整段长度 >= 2 且所有数都一样就无法合并
否则一定可以合并，我们可以直接找严格比某个周围元素大的最大值，然后执行合并
*/

struct Operation {
    int pos;
    char direction;
};

void meibao() {
    int n, m;
    cin >> n;
    vector<int> sum(n + 1, 0), a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        a[i] = sum[i];
        sum[i] += sum[i - 1];
    }
    cin >> m;
    vector<int> b(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int match_cnt = 0;
    int left = 0, idx = 1;
    int right;
    vector<Operation> ops;
    vector<PII> segs;
    for (right = 1; right <= n && idx <= m; right++) {
        if (sum[right] - sum[left] == b[idx]) {
            idx++;
            segs.push_back({left + 1, right});
            left = right;
        } else if (sum[right] - sum[left] > b[idx]) {
            cout << "NO\n";
            return;
        } 
    }
    
    if (right != n + 1 || idx != m + 1) {
        cout << "NO\n";
        return;
    }

    for (auto seg : segs) {
        int len = seg.y - seg.x + 1;
        if (len == 1) {
            match_cnt++;
            continue;
        }
        int mx = a[seg.x], pos = -1;
        bool all_same = true;
        for (int i = seg.x + 1; i <= seg.y; i++) {
            if (a[i] != a[i - 1]) {
                all_same = false;
                mx = max(mx, a[i]);
            }
        }
        if (all_same) {
            cout << "NO\n";
            return;
        }
        for (int i = seg.x; i < seg.y; i++) {
            if (a[i] == mx && a[i] > a[i + 1]) {
                pos = i;
            }
        }
        if (pos != -1 && pos + 1 <= seg.y && a[pos] > a[pos + 1]) {
            int cur_pos = pos - seg.x + 1 + match_cnt;
            for (int i = pos + 1; i <= seg.y; i++) {
                ops.push_back({cur_pos, 'R'});
            }
            for (int i = pos - 1; i >= seg.x; i--) {
                ops.push_back({cur_pos, 'L'});
                cur_pos--;
            }
            match_cnt++;
        } else {
            for (int i = seg.x + 1; i <= seg.y; i++) {
                if (a[i] == mx && a[i - 1] < a[i]) {
                    pos = i;
                }
            }
            if (pos - 1 >= seg.x && a[pos] > a[pos - 1]) {
                int cur_pos = pos - seg.x + 1 + match_cnt;
                for (int i = pos - 1; i >= seg.x; i--) {
                    ops.push_back({cur_pos, 'L'});
                    cur_pos--;
                }
                for (int i = pos + 1; i <= seg.y; i++) {
                    ops.push_back({cur_pos, 'R'});
                }
                match_cnt++;
            } else {
                for (int i = seg.x; i <= seg.y; i++) {
                    cout << a[i] << " ";
                }
                return;
            }
        }
    }
    cout << "YES\n";
    for (auto op : ops) {
        cout << op.pos << " " << op.direction << "\n";
    }
}
