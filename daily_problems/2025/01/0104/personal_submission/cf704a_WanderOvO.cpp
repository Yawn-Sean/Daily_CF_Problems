/*
维护一个长为 q 的时间轴
维护 2 操作最长到了哪个时间戳，假设是 latest
每个应用维护自己还有哪些没被处理的消息(的时间)
每来一条新消息，树状数组的相应时间上增加一个，应用的 vector 中增加一个
读前 t 个消息好做，知道第 t 条消息的时间戳就行了，然后更新 latest
一个应用的所有消息已读，我们枚举这个应用存的所有消息，然后挨个在树状数组中删掉（每条消息至多增删一次），再把 vector 删了
询问时，只需要询问 [latest + 1, cur] 之间的即可，被重复删掉的单独的不影响答案
*/

BIT tr;
int n, q, latest = 0, times[N], idx = 0;
vector<vector<int>> e(N);

void meibao() {
    cin >> n >> q;
    tr.init(q);
    for (int i = 1; i <= q; i++) {
        int op, x, t;
        cin >> op;
        if (op == 1) {
            cin >> x;
            e[x].push_back(i);
            tr.add(i, 1);
            times[++idx] = i;
        } else if (op == 2) {
            cin >> x;
            for (auto pos : e[x]) {
                tr.add(pos, -1);
            }
            e[x].clear();
        } else {
            cin >> t;
            latest = max(latest, times[t]);
        }
        cout << tr.query(i) - tr.query(latest) << "\n";
    }
}
