int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    vector<array<int, 2>> pre_odd(n), suf_odd(n);
    vector<array<int, 2>> pre_even(n), suf_even(n);
    int lst_odd = -1, lst_even = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre_odd[i][0] = lst_odd + 1;
        pre_even[i][0] = lst_even + 1;
        if (a[i] & 1) {
            lst_odd++;
            lst_even = -1;
        } else {
            lst_even++;
            lst_odd = -1;
        }
    }
    lst_odd = lst_even = -1;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pre_odd[i][1] = lst_odd + 1;
        pre_even[i][1] = lst_even + 1;
        if (b[i] & 1) {
            lst_odd++;
            lst_even = -1;
        } else {
            lst_even++;
            lst_odd = -1;
        }
    }
    lst_odd = lst_even = -1;
    for (int i = n - 1; i >= 0; i--) {
        suf_odd[i][0] = lst_odd + 1;
        suf_even[i][0] = lst_even + 1;
        if (a[i] & 1) {
            lst_odd++;
            lst_even = -1;
        } else {
            lst_even++;
            lst_odd = -1;
        }
    }
    lst_odd = lst_even = -1;
    for (int i = n - 1; i >= 0; i--) {
        suf_odd[i][1] = lst_odd + 1;
        suf_even[i][1] = lst_even + 1;
        if (b[i] & 1) {
            lst_odd++;
            lst_even = -1;
        } else {
            lst_even++;
            lst_odd = -1;
        }
    }
 
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        if (a[x1] & 1) {
            assert(b[y1] & 1);
            int al = x1 - pre_odd[x1][0], ar = x1 + suf_odd[x1][0];
            int bl = y1 - pre_odd[y1][1], br = y1 + suf_odd[y1][1];
            bool ok = false;
            if (x2 >= al && x2 <= ar && y2 >= bl && y2 <= br) ok = true;
            cout << (ok ? "YES" : "NO") << '\n';
        } else {
            assert(b[y1] % 2 == 0);
            int al = x1 - pre_even[x1][0], ar = x1 + suf_even[x1][0];
            int bl = y1 - pre_even[y1][1], br = y1 + suf_even[y1][1];
            debug(al, ar, bl, br);
            bool ok = false;
            if (x2 >= al && x2 <= ar && y2 >= bl && y2 <= br) ok = true;
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
 
 
    return 0;
}
