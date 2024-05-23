/*
压缩相同的字符
a(2)b(1)c(1)a(2)

假如某个字符本轮被删除了，那么其两边的字符都是下轮要考虑的对象
假如某个字符左右两边的字符本轮都没有被删除，则下轮无需考虑该字符

先把初始需要删的点存一下，然后做第一轮删除

*/

int T;
int n, pre[N], ne[N];
string s;
bool deleted[N];

void del(int p) {
    int pre_p = pre[p], ne_p = ne[p];
    if (pre_p != -1) {
        ne[pre_p] = ne_p;
    }
    if (ne_p != -1) {
        pre[ne_p] = pre_p;
    }
}

void solve1() {
    cin >> s;
    n = s.size();
    s = " " + s;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = -1;
    ne[n] = -1;

    unordered_set<int> to_delete;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && i < n) {
            if (s[i] != s[i - 1] || s[i] != s[i + 1]) {
                to_delete.insert(i);
            }
        } else if (i == 1) {
            if (s[i] != s[i + 1]) {
                to_delete.insert(i);
            }
        } else if (i == n) {
            if (s[i] != s[i - 1]) {
                to_delete.insert(i);
            }
        }
    }
    int res = 0;
    while (to_delete.size() > 0) { 
        // cout << "round: " << res << "\n";
        // cout << to_delete.size() << "\n";
        unordered_set<int> actually_to_delete;
        for (auto &p : to_delete) {
            if (!deleted[p]) {
                int pre_p = pre[p], ne_p = ne[p];
                if ( (pre_p != -1 && s[pre_p] != s[p]) || (ne_p != -1 && s[ne_p] != s[p]) ) {
                    actually_to_delete.insert(p);
                } 
            }
        }
        if (actually_to_delete.size() > 0) {
            res++;
        } else {
            break;
        }
        
        // TODO: 执行删除
        for (auto &p : actually_to_delete) {
            // cout << "del: " << p << "\n";
            deleted[p] = true;
            del(p);
        }        

        to_delete.clear();
        for (auto &p : actually_to_delete) {
            int pre_p = pre[p], ne_p = ne[p];
            if (pre_p != -1 && !deleted[pre_p]) {
                to_delete.insert(pre_p);
            }
            if (ne_p != -1 && !deleted[ne_p]) {
                to_delete.insert(ne_p);
            }
        }
    }
    cout << res << endl;
}         