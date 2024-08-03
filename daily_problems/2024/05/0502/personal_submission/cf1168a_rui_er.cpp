const int N = 3e5 + 5, inf = 0x3f3f3f3f;

int T, n, m, a[N];

int calc(int u, int v) {
    return u <= v ? v - u : v + m - u;
}

bool check(int mid) {
    int j = 0;
    rep(i, 1, n) {
        while(j < m && calc(a[i], j) > mid) ++j;
        if(j >= m) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    int l = 0, r = m + 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
