int T;
MyHash h;
int n, m, p[N], d[N];
string s;

void solve1() {
    cin >> n >> m >> s;
    int len = s.size();
    int hash_mod = MOD1 + 1000 + rand() % 1000;
    h.init(s, P, hash_mod);
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    for (int i = 2; i <= m; i++) {
        if (p[i] - p[i - 1] >= len) {
            continue;
        }
        int st = p[i] - p[i - 1];
        if (h.get(st, len - 1) != h.get(0, len - st - 1)) {
            cout << "0\n";
            return;
        }
    }

    for (int i = 1; i <= m; i++) {
        d[p[i]]++;
        d[p[i] + len]--;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        if (d[i] == 0) {
            cnt++;
        }
    }
    cout << qpow(26, cnt, MOD1);
}         