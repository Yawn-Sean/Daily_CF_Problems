/*
假设 cnt 天到顶，则应该满足：
(a - b) * (cnt - 1) + a >= target >= (a - b) * (cnt - 2) + a + 1
*/

LL q;

void meibao() {
    cin >> q;
    LL lo = 1, hi = 2e18;

    auto calc = [&] (LL lo, LL hi, LL a, LL b) -> LL {
        LL d = a - b;
        lo -= a;
        LL cnt1 = (lo <= 0) ? 1 : ((lo + d - 1) / d + 1);
        hi -= a;
        LL cnt2 = (hi <= 0) ? 1 : ((hi + d - 1) / d + 1);
        if (cnt1 == cnt2) {
            return cnt1;
        }
        return -1;
    };  

    while (q--) {
        LL type, a, b, cnt;
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> cnt;
            LL new_lo, new_hi;
            if (cnt == 1) {
                new_lo = 1;
                new_hi = a;
            } else {
                new_lo = (a - b) * (cnt - 2) + a + 1;
                new_hi = (a - b) * (cnt - 1) + a;
            }
            if (new_hi < lo || new_lo > hi) {
                cout << "0 ";
            } else {
                cout << "1 ";
                hi = min(hi, new_hi);
                lo = max(lo, new_lo);
            }
        } else {
            cin >> a >> b;
            cout << calc(lo, hi, a, b) << " ";
        }
    }
    cout << "\n";
}
