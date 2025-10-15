/*
比较关键的是最晚到的人和最早走的人
由于到和走的当天都不算工作，所以要求最早走的时间 - 最晚到的时间 - 1 >= k
不妨把从 0 出发和到达 0 的航班分别组织，分别按照时间排序
两个指针，枚举最晚到的航班和最早离开的航班，二者时间差距满足上式
在到 0 的航班里，动态维护每个人来到 0 的最小花费
在离开 0 的航班里，动态维护每个人离开 0 的最小花费
前后缀组合一下得到答案
注意判断必须所有人都到了 0，以及所有人都能离开 0，所以要预处理一下这个边界是多少
*/ 

struct Ticket {
    LL d, f, t, c;

    bool operator<(const Ticket &o) const {
        return d < o.d;
    }
};

Ticket go[N];
Ticket back[N];
LL n, m, k, cnt1, cnt2, go_sum[N], back_sum[N], min_go[N], min_back[N];

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        Ticket t;
        cin >> t.d >> t.f >> t.t >> t.c;
        if (t.f == 0) {
            back[++cnt2] = t;
        } else {
            go[++cnt1] = t;
        }
    }

    sort(go + 1, go + cnt1 + 1);
    sort(back + 1, back + cnt2 + 1);

    int all_go_pos = -1, all_back_pos = -1;
    set<int> st;
    for (int i = 1; i <= cnt1; i++) {
        st.insert(go[i].f);
        if (st.size() == n) {
            all_go_pos = i;
            break;
        }
    }
    st.clear();
    for (int i = cnt2; i > 0; i--) {
        st.insert(back[i].t);
        if (st.size() == n) {
            all_back_pos = i;
            break;
        }
    }

    if (all_go_pos == -1 || all_back_pos == -1) {
        cout << "-1\n";
        return;
    }

    memset(min_go, 0x3f, sizeof min_go);
    memset(min_back, 0x3f, sizeof min_back);

    for (int i = 1; i <= all_go_pos; i++) {
        LL id = go[i].f, c = go[i].c;
        min_go[id] = min(min_go[id], c);
    }
    for (int i = 1; i <= n; i++) {
        go_sum[all_go_pos] += min_go[i];
    }
    for (int i = all_go_pos + 1; i <= cnt1; i++) {
        LL id = go[i].f, c = go[i].c;
        go_sum[i] = go_sum[i - 1];
        if (min_go[id] > c) {
            go_sum[i] -= min_go[id];
            go_sum[i] += c;
            min_go[id] = c;
        }
    }

    for (int i = cnt2; i >= all_back_pos; i--) {
        LL id = back[i].t, c = back[i].c;
        min_back[id] = min(min_back[id], c);
    }
    for (int i = 1; i <= n; i++) {
        back_sum[all_back_pos] += min_back[i];
    }
    for (int i = all_back_pos - 1; i > 0; i--) {
        LL id = back[i].t, c = back[i].c;
        back_sum[i] = back_sum[i + 1];
        if (min_back[id] > c) {
            back_sum[i] -= min_back[id];
            back_sum[i] += c;
            min_back[id] = c;
        }
    }

    int p1 = all_go_pos, p2 = 1;
    LL res = INFLL;
    for ( ; p1 <= cnt1 && p2 <= all_back_pos; p1++) {
        while (p2 <= all_back_pos && back[p2].d - go[p1].d - 1 < k) {
            p2++;
        }
        if (p2 <= all_back_pos) {
            res = min(res, go_sum[p1] + back_sum[p2]);
        }
    }
    if (res == INFLL) {
        res = -1;
    }
    cout << res << "\n";
}
