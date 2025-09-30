/*
为什么是 (n + 1) / 2 次
1 2 3 4
1 2
2 3

5 2 3 4 1
2 3 5
2 3 4
1 3 4

5 6 1 3 4 2
1 5 6
1 3 6
1 3 4

8 6 5 7 4 3 2 1
5 6 7 8
4 5 6 7
3 4 5 7
2 3 4 7
我们考虑询问长度为 (n + 1) / 2 的区间，就可以一次确定两个数
*/

int n;
int res[N];
vector<set<int>> query_res;

void meibao() {
    cin >> n;
    int len = (n + 1) / 2;

    auto query = [&] (int l, int r) -> set<int> {
        set<int> q;
        cout << "Q " << l << " " << r << endl;
        for (int i = l; i <= r; i++) {
            int val;
            cin >> val;
            q.insert(val);
        }
        return q;
    };
    int mx = (n % 2 == 0 ? n - 1 : n);
    for (int i = 1; i + len - 1 <= mx; i++) {
        set<int> q = query(i, i + len - 1);
        query_res.push_back(q);
    }

    for (int i = 1; i < query_res.size(); i++) {
        for (auto val : query_res[i]) {
            if (!query_res[i - 1].count(val)) {
                res[i + len] = val;
            }
        }
        for (auto val : query_res[i - 1]) {
            if (!query_res[i].count(val)) {
                res[i] = val;
            }
        }
    }

    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 0; i < query_res.size(); i++) {
        for (auto val : query_res[i]) {
            st.erase(val);
        }
    }

    if (st.size() == 1) {
        res[n] = *st.begin();
    }

    st.clear();
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (res[i]) {
            st.erase(res[i]);
        } else {
            pos = i;
        }
    }

    if (st.size() == 1) {
        res[pos] = *st.begin();
    }

    cout << "A ";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}   
