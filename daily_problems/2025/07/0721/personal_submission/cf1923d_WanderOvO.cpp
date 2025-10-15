ST_MAX st_max;
ST_MIN st_min;
LL a[N], s[N], n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    st_max.init_st(a, n);
    st_min.init_st(a, n);

    auto check = [&] (int ans, int pos) -> bool {
        if (pos < n) {
            LL right = pos + ans;
            right = min(right, n);
            LL mx = st_max.query(pos + 1, right), mn = st_min.query(pos + 1, right);
            if (right - pos == 1 || mx != mn) {
                if (s[right] - s[pos] > a[pos]) {
                    return true;
                } 
            } else if (mx == mn) {
                if (mx > a[pos]) {
                    return true;
                }
            }
        }

        if (pos > 1) {
            LL left = pos - ans;
            left = max(left, 1LL);
            LL mx = st_max.query(left, pos - 1), mn = st_min.query(left, pos - 1);
            if (pos - left == 1 || mx != mn) {
                if (s[pos - 1] - s[left - 1] > a[pos]) {
                    return true;
                }
            } else if (mx == mn) {
                if (mx > a[pos]) {
                    return true;
                }
            }
        }   

        return false;
    };

    for (int i = 1; i <= n; i++) {
        int l = 1, r = n, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(mid, i)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check(l, i)) {
            cout << l << " ";
        } else if (check(r, i)) {
            cout << r << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";
}
