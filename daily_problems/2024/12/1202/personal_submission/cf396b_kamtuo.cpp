/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2024-12-02 15:53                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    const int N = 51234;
    vector p(N, 0), st(N, 0);
    int cnt = 0;
    for (int i = 2; i < N; i ++) {
        if (st[i] == 0) p[cnt ++] = i;
        for (int j = 0; p[j] * 1ll * i < N; j ++) {
            st[p[j] * i] = 1;
            if (i % p[j] == 0) break;
        }
    }
    std::function<LL (LL, LL)> gcd = [&] (LL a, LL b) -> LL {
        if (b == 0) return a;
        return gcd(b, a % b);
    };
    auto cal = [&] (LL &p, LL &q, LL b, LL a) {
        LL g = gcd(q, a);
        LL l = q * a / g;
        p *= l / q;
        b *= l / a;
        q = a = l;
        p += b;
        g = gcd(q, p);
        p /= g;
        q /= g;
    };
    while (t --) {
        int n;
        cin >> n;
        LL u, v;
        for (u = n; ; u --) {
            bool ok = true;
            for (int j = 0; j < cnt && p[j] < u; j ++) {
                if (u % p[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
        }
        for (v = n + 1; ; v ++) {
            bool ok = true;
            for (int j = 0; j < cnt && p[j] < v; j ++) {
                if (v % p[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
        }
        // debug("u:", u, "v:", v);
        LL p = 1, q = 2;
        cal(p, q, n + 1 - u - v, u * v);
        cout << p << "/" << q << "\n";
    }
    return 0;
}

#endif

/*

*/
