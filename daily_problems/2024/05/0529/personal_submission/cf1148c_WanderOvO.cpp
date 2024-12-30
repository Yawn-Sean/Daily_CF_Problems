/*
给了 5n 的操作次数，所以目标至多 5 次确定一个元素的位置
如何实现任意两个数的交换？
如果这两个数下标都在 [1, n / 2] 或者 [n / 2 + 1, n]，则只需要用最右/最左的当作中介
如果这两个数下标 pos1, pos2 在两边，pos1 < pos2，则用 1 和 n 当中介
每次找最小的那个数，然后交换到相应的位置
*/

int T;
int n, pos_val[N], val_pos[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos_val[i];
        val_pos[pos_val[i]] = i;
    }
    vector<PII> ops;
    for (int i = 1; i <= n; i++) {
        int val1 = i, pos1 = val_pos[i];
        int pos2 = i, val2 = pos_val[pos2];
        if (pos1 == pos2) {
            continue;
        }
        if (pos1 > pos2) {
            swap(pos1, pos2);
            swap(val1, val2);
        }

        if (pos2 <= n / 2) {
            ops.pb({pos2, n});
            ops.pb({pos1, n});
            ops.pb({pos2, n});
        } else if (pos1 > n / 2) {
            ops.pb({1, pos2});
            ops.pb({1, pos1});
            ops.pb({1, pos2});
        } else {
            if (pos1 == 1) {
                ops.pb({pos1, pos2});
            } else if (pos2 == n) {
                ops.pb({pos1, pos2});
            } else {
                ops.pb({1, pos2});
                ops.pb({1, n});
                ops.pb({pos1, n});
                ops.pb({1, n});
                ops.pb({1, pos2});
            }
        }
        val_pos[val1] = pos2;
        val_pos[val2] = pos1;
        pos_val[pos2] = val1;
        pos_val[pos1] = val2;
    }
    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++) {
        cout << ops[i].x << " " << ops[i].y << "\n";
    }
}         