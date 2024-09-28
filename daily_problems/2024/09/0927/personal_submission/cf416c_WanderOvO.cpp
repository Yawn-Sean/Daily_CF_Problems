/*
对于每个桌子，尽量要钱多且人多的
优先用小桌子，小桌子放自己能放下的人里面的最贵的那个
*/
int c[N], p[N], n, k;
PII r[N];
bool vis[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> p[i];
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> r[i].x;
        r[i].y = i;
    }
    sort(r + 1, r + k + 1);
    LL res = 0;
    vector<PII> plans;
    for (int i = 1; i <= k; i++) {
        int pos = 0, val = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && r[i].x >= c[j] && p[j] > val) {
                val = p[j];
                pos = j;
            }
        }
        if (pos != 0) {
            vis[pos] = true;
            res += val;
            plans.pb({pos, r[i].y});
        }
    }
    cout << plans.size() << " " << res << "\n";
    for (auto plan : plans) {
        cout << plan.x << " " << plan.y << "\n";
    }
}    
