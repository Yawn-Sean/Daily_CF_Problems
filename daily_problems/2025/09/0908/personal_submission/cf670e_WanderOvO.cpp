/*
光标移到了 i 位置，则需要删除从 i 到和 i 配对的那个括号之间（包括他们两个）的所有内容
先使用栈预处理括号匹配
建一个双向链表，维护所有的括号
移动就正常移动，删除时，对于编号为 i 的括号，找到其配对的括号 j
如果是 (i, j)，则让 i 的上一个结点指向 j 的下一个结点
如果是 (j, i)，则让 j 的上一个结点指向 i 的下一个结点
注意游标的移动，理论上是移动到右边那个，但有可能右边的删完了，这个时候就得往左移动了
*/

struct Node {
    int pre, next, id;
};

int n, m, p;
string s;
string t;
Node a[N];
int match[N];

void meibao() {
    cin >> n >> m >> p >> s >> t;
    for (int i = 1; i <= n; i++) {
        a[i].pre = i - 1;
        a[i].next = i + 1;
        a[i].id = i;
    }
    a[0].pre = -1;
    a[0].next = 1;
    a[n + 1].pre = n;
    a[n + 1].next = -1;

    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push_back(i + 1);
        } else {
            match[i + 1] = stk.back();
            match[stk.back()] = i + 1;
            stk.pop_back();
        }
    }

    assert(stk.size() == 0);

    for (int idx = 0; idx < m; idx++) {
        if (t[idx] == 'L') {
            p = a[p].pre;
        } else if (t[idx] == 'R') {
            p = a[p].next;
        } else {
            int i = p, j = match[p];
            if (i > j) {
                swap(i, j);
            }

            int l = a[i].pre, r = a[j].next;
            assert(l >= 0);
            assert(r >= 0);
            a[l].next = r;
            a[r].pre = l;
            if (r != n + 1) {
                p = r;
            } else {
                p = l;
            }
        }
    }

    p = 0;
    while (p != n + 1) {
        p = a[p].next;
        if (p != n + 1) {
            cout << s[p - 1];
        }
    }
}   
