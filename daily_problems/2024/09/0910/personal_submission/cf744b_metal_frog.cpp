struct Q {
    pii queryRange, resUpdateRange;
    int tp;
};
 
vector<Q> levelQ[100];
 
void query(int level, int lo, int hi) {
    if (lo == hi) return;
    int mid = lo + (hi - lo) / 2;
    Q q1;
    q1.queryRange = {mid + 1, hi};
    q1.resUpdateRange = {lo, mid};
    q1.tp = 1;
    Q q2;
    q2.queryRange = {lo, mid};
    q2.resUpdateRange = {mid + 1, hi};
    q2.tp = 2;
    levelQ[level].emplace_back(q1);
    levelQ[level].emplace_back(q2);
    query(level + 1, lo, mid);
    query(level + 1, mid + 1, hi);
}
 
void solve() {
    int n;
    scanf("%d", &n);
    vector<int> rowMin(n + 1, 1e9);
    vector<int> buf(2 * n);
    query(0, 1, n);
    for (int level = 0; level < 10; level++) {
        if (levelQ[level].empty()) break;
        vector<int> qbuf[3], needCheck[3];
        needCheck[1].resize(n + 1);
        needCheck[2].resize(n + 1);
        for (Q& q : levelQ[level]) {
            auto [st, ed] = q.queryRange;
            for (int i = st; i <= ed; i++) qbuf[q.tp].emplace_back(i);
            auto [chkSt, chkEd] = q.resUpdateRange;
            for (int i = chkSt; i <= chkEd; i++) needCheck[q.tp][i] = 1;
        }
        if (!qbuf[1].empty()) {
            printf("%d\n", sz(qbuf[1]));
            for (int x : qbuf[1]) {
                printf("%d ", x);
            }
            printf("\n");
            fflush(stdout);
            for (int i = 1; i <= n; i++) {
                int x;
                scanf("%d", &x);
                if (needCheck[1][i]) rowMin[i] = min(rowMin[i], x); 
            }
        }
        if (!qbuf[2].empty()) {
            printf("%d\n", sz(qbuf[2]));
            for (int x : qbuf[2]) {
                printf("%d ", x);
            }
            printf("\n");
            fflush(stdout);
            for (int i = 1; i <= n; i++) {
                int x;
                scanf("%d", &x);
                if (needCheck[2][i]) rowMin[i] = min(rowMin[i], x); 
            }
        }
    }
    printf("-1\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", rowMin[i]);
    }
    fflush(stdout);
}
 
