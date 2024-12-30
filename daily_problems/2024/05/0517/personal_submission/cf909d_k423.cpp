// https://codeforces.com/contest/909/submission/261269717

/* 我永远喜欢爱莉希雅♪ */
struct node {
    char x;
    int id, del;
    node *pre, *nxt;

    node(char v = '#', int _id = -1, node *_pre = 0, node *_nxt = 0)
            : x(v), id(_id), del(0), pre(_pre), nxt(_nxt) {}
};

void elysia() {
    string s;
    cin >> s;
    int n = s.size();
    node *head = new node('#', -1), *tail = new node('#', n), *cur = head;
    head->nxt = tail, tail->pre = head;
    vector<node *> nodes(n), dels;
    for (int i = 0; i < n; ++i) {
        cur->nxt = nodes[i] = new node(s[i], i, cur, cur->nxt);
        cur = cur->nxt;
        cur->nxt->pre = cur;
        int del = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i && nodes[i]->x != nodes[i]->pre->x || i + 1 < n && nodes[i]->x != nodes[i]->nxt->x) {
            dels.emplace_back(nodes[i]);
        }
    }
    int ans = 0;
    vector<int> vis(n);
    while (!dels.empty()) {
        ans++;
        for (node *p: dels) {
            p->del = 1;
            p->pre->nxt = p->nxt;
            p->nxt->pre = p->pre;
        }
        vector<node *> tmp;
        for (node *p: dels) {
            if (!p->pre->del && p->pre->x != '#' && p->pre->nxt->x != '#' && p->pre->x != p->pre->nxt->x) {
                if (!vis[p->pre->id]) tmp.emplace_back(p->pre), vis[p->pre->id] = 1;
            }
            if (!p->nxt->del && p->nxt->x != '#' && p->nxt->pre->x != '#' && p->nxt->x != p->nxt->pre->x) {
                if (!vis[p->nxt->id]) tmp.emplace_back(p->nxt), vis[p->nxt->id] = 1;
            }
        }
        dels.swap(tmp);
    }
    cout << ans << endl;
}
