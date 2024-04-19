/*
第一关键字为值，第二关键字为代价，扔到堆里面
每次如果遇到的没见过的值，就把代价最大的弹出来
*/

int T;
int n;
PLL a[N];
priority_queue<LL> q;
set<int> vals;

bool cmp(const PLL &p1, const PLL &p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
} 

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].y;
    }
    
    sort(a + 1, a + n + 1, cmp);
    
    LL res = 0, cur = 0, cost = 0;
    for (int i = 1; i <= n || q.size() > 0; cur++) {
        if (q.size() == 0) {
            cur = a[i].x;
        }
        for (; i <= n && a[i].x == cur; i++) {
            q.push(a[i].y);
            cost += a[i].y;
        }
        LL u = q.top();
        q.pop();
        cost -= u;
        res += cost;
    }
    cout << res << "\n";
}