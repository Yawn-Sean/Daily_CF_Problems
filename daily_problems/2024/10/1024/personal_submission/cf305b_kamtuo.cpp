/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-24 09:28 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long q, p;
    cin >> q >> p;
    int n;
    cin >> n;
    vector a(n, 0ll);
    for (int i = 0; i < n; i ++) cin >> a[i];
    auto reverse = [&] (LL &q, LL &p) {
        std::swap(q, p);
    };
    // p / q
    std::function<LL (LL, LL)> gcd = [&] (LL a, LL b) -> LL {
        if (b) return gcd(b, a % b);
        return a;
    };
    auto add = [&] (LL &q, LL &p, LL a, LL b) {
        LL g = gcd(q, a);
        LL l = q * a / g;
        p *= l / q;
        b *= l / a;
        q = a = l;
        p += b;
        g = gcd(q, p);
        q /= g;
        p /= g;
    };
    LL na = 1, nb = 0;
    for (int i = n - 1; i >= 0; i --) {
        LL nowq = 1, nowp = a[i];
        add(na, nb, nowq, nowp);
        reverse(na, nb);
    };
    // reverse(na, nb);
    LL g = gcd(na, nb);
    na /= g, nb /= g;
    g = gcd(p, q);
    p /= g, q /= g;
    // debug("na:", na, "nb:", nb);
    if (na == q && nb == p) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}

#endif

/*

*/
