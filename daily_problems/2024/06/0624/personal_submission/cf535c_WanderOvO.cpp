int T;
LL A, B, n;

LL get_s(LL i) {
    return A + (i - 1) * B;
}

bool check(LL l, LL r, LL t, LL m) {
    if (get_s(r) > t) {
        return false;
    }
    LL cnt = r - l + 1, fi = get_s(l), la = get_s(r);
    return cnt * (fi + la) / 2 <= t * m;
}

void solve1() {
    cin >> A >> B >> n;
    LL left, t, m;
    while (n--) {
        cin >> left >> t >> m;
        LL l = left, r = 1e6, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(left, mid, t, m)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (check(left, r, t, m)) {
            cout << r << "\n";
        } else if (check(left, l, t, m)) {
            cout << l << "\n";
        } else {
            cout << "-1\n";
        }
    }
}                     