/*
假如第 i 个操作是排序 [1, r]，而之前出现的右端点都比 r 小，则之前的那些都不用考虑
所以我们先找到最大的那个操作区间，然后看它之后操作的最大区间...
这些组成一系列长度单调递减的前缀
然后我们遍历这些操作
假如这次操作是 [1, r1]，下次是 [1, r2]，r1 >= r2 则本次能确定 [r2 + 1, r1] 的数
用 multiset 不断弹出当前最大值或者最小值即可
如果第一个区间不是 [1, n]，则 [r1 + 1, n] 就不要变
*/

int T;
LL n, m, a[N], res[N];
stack<PII> st;
multiset<int> s;

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        int op, r;
        cin >> op >> r;
        while (!st.empty()) {
            if (r >= st.top().x) {
                st.pop();
            } else {
                break;
            }
        }
        st.push({r, op});
    }
    
    vector<PII> b;
    while (!st.empty()) {
        b.pb(st.top());
        st.pop();
    }
    reverse(b.begin(), b.end());
    if (b.size() > 0) {
        for (int i = b[0].x + 1; i <= n; i++) {
            res[i] = a[i];
        }
        for (int i = 1; i <= b[0].x; i++) {
            s.insert(a[i]);
        }
        
        // pos: 接下来该确定哪个位置了
        int last = b[0].x, pos = b[0].x;
        for (int i = 1; i < b.size(); i++) {
            int cnt = last - b[i].x;
            while (cnt--) {
                int val;
                if (b[i - 1].y == 2) {
                    val = *s.begin();
                } else {
                    val = *prev(s.end());
                }
                auto it = s.find(val);
                s.erase(it);
                res[pos] = val;
                pos--;
            }
            last = b[i].x;
        }
        if (pos > 0) {
            int cnt = last;
            while (cnt--) {
                int val;
                if (b.back().y == 2) {
                    val = *s.begin();
                } else {
                    val = *prev(s.end());
                }
                auto it = s.find(val);
                s.erase(it);
                res[pos] = val;
                pos--;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}   