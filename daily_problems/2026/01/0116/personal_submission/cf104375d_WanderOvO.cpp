/*
对于操作 1：
- 把目前序列中 >= k 的最小的数替换成 k
- 如果所有数都严格小于 k，则增加一个 k

对于操作 2：
询问 [a, b] 中有多少个数

一个比较暴力的做法是，维护一个 multiset 和一个动态开点权值线段树
使用 multiset 的二分去看第一个操作应该搞哪个数
其实就是在权值线段树里把某个数次数 -1，k 的次数 + 1
如果离散化的话，权值树状数组搞一下就好了，至多可能出现 3e6 种数值
*/

struct Fenwick {
    vector<int> tr;
    int n;
    
    Fenwick(int sz) {
        n = sz;
        tr.assign(n + 1, 0);
    }    
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void modify(int pos, int val) {
        while (pos <= n) {
            tr[pos] += val;
            pos += lowbit(pos);
        }
    }
    
    int query(int pos) {
        int res = 0;
        while (pos) {
            res += tr[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
};

struct Query {
    int op_type;
    int k, a, b;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> origin_val;
    origin_val.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        origin_val.push_back(a[i]);
    }   
    
    vector<Query> ops(q + 1);
    for (int i = 1; i <= q; i++) {
        int op_type;
        cin >> op_type;
        ops[i].op_type = op_type;
        if (op_type == 1) {
            cin >> ops[i].k;
            origin_val.push_back(ops[i].k);
        } else {
            cin >> ops[i].a >> ops[i].b;
            origin_val.push_back(ops[i].a);
            origin_val.push_back(ops[i].b);
        }
    }
    
    sort(origin_val.begin(), origin_val.end());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(origin_val.begin(), origin_val.end(), a[i]) - origin_val.begin();
    }

    for (int i = 1; i <= q; i++) {
        if (ops[i].op_type == 1) {
            ops[i].k = lower_bound(origin_val.begin(), origin_val.end(), ops[i].k) - origin_val.begin();
        } else {
            ops[i].a = lower_bound(origin_val.begin(), origin_val.end(), ops[i].a) - origin_val.begin();
            ops[i].b = lower_bound(origin_val.begin(), origin_val.end(), ops[i].b) - origin_val.begin();
        }
    }

    multiset<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(a[i]);
    }

    Fenwick fen(n + 2 * q + 1);
    for (int i = 1; i <= n; i++) {
        fen.modify(a[i], 1);
    }

    for (int i = 1; i <= q; i++) {
        if (ops[i].op_type == 1) {
            auto it = st.lower_bound(ops[i].k);
            if (it == st.end()) {
                st.insert(ops[i].k);
                fen.modify(ops[i].k, 1);
            } else {
                int old_val = *it;
                fen.modify(old_val, -1);
                fen.modify(ops[i].k, 1);
                st.erase(it);
                st.insert(ops[i].k);
            }
        } else {
            cout << fen.query(ops[i].b) - fen.query(ops[i].a - 1) << "\n";
        }
    }
}
