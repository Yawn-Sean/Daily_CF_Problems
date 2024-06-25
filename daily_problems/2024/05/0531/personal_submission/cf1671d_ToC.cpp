// https://codeforces.com/contest/1671/submission/263578027
int n, m, x;
int a[MAXN];
void sol()
{
    cin >> n >> x;
    int maxv = -1, minv = INF;
    int maxi = -1, mini = -1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] > maxv) {
            maxv = a[i];
            maxi = i;
        } 
        if (a[i] < minv) {
            minv = a[i];
            mini = i;
        }
    }
    if (n <= 2) {
        cout << max(maxv, x) - 1 << '\n';
        return ;
    }
    int delta = 0;
    if (1 < minv) {
        delta += min({2 * (minv - 1), a[1] - 1, a[n] - 1});
    }
    if (x > maxv) {
        delta += min({2 * (x - maxv), x - a[1], x - a[n]});
    }
    enum DIR {up, down, unk}; // 向上、向下、未知
    DIR dir = unk;
    int last, cur;
    int left = 1, right = 1;
    vector<PII> history;
    for (int i = 2; i <= n; i++) {
        last = a[i - 1], cur = a[i];
        if (dir == unk) {
            if (cur > last) {
                dir = up;
            } else if (cur < last) {
                dir = down;
            }
        } else if (dir == up) {
            if (cur >= last) {
                ;
            } else {
                dir = down;
                history.push_back({left, i - 1});
                left = i - 1;
            }
        } else {
            if (cur <= last) {
                ;
            } else {
                dir = up;
                history.push_back({left, i - 1});
                left = i - 1;
            }
        }
    }
    history.push_back({left, n});
    LL tot = delta;
    for (auto &[l, r] : history) {
        tot += abs(a[l] - a[r]);
    }
    cout << tot << '\n';
}
