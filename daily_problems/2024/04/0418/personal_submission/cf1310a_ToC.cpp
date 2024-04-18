// https://codeforces.com/contest/1310/submission/257177977
int n, t, m;
PII ap[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ap[i].first;
    for (int i = 1; i <= n; i++) cin >> ap[i].second;
    sort(ap + 1, ap + n + 1);
    priority_queue<PII> pq;
    LL res = 0, tot = 0;
    int idx = 1, now = 0;
    while (idx <= n || !pq.empty()) {
        now++;  //本次至少要使得剩余元素最小值为now
        if (pq.empty()) {
            now = ap[idx].first;
            while (idx <= n && ap[idx].first == now) {
                pq.push({ap[idx].second, ap[idx].first});
                tot += ap[idx].second;
                idx++;
            }
        } else {
            while (idx <= n && ap[idx].first == now) {
                pq.push({ap[idx].second, ap[idx].first});
                tot += ap[idx].second;
                idx++;
            }
        }
        tot -= pq.top().first; pq.pop();    //保留单价最大的一个
        res += tot;
    }
    cout << res << '\n';
}
