const int N = 1e5 + 5;

int n, s[N], id[N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 0, n - 1) cin >> s[i];
    rep(i, 0, n - 1) id[i] = i;
    sort(id, id + n, [&](int x, int y) {
        return s[x] < s[y];
    });
    rep(i, 0, n - 1) {
        if(i < (n + 2) / 3) {
            a[id[i]] = i;
            b[id[i]] = s[id[i]] - a[id[i]];
        }
        else if(i < (n + 2) / 3 * 2) {
            b[id[i]] = i;
            a[id[i]] = s[id[i]] - b[id[i]];
        }
        else {
            b[id[i]] = n - 1 - i;
            a[id[i]] = s[id[i]] - b[id[i]];
        }
    }
    cout << "YES" << endl;
    rep(i, 0, n - 1) cout << a[i] << " \n"[i == n - 1];
    rep(i, 0, n - 1) cout << b[i] << " \n"[i == n - 1];
    return 0;
}
