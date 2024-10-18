/*
由于要求恰好有一个人做出来，所以人选多了未必会更优
通过打表，假如存在 >= 0.5 的，就是单独选最大的，都 < 0.5，似乎是选最大的几个，至于具体选几个需要枚举一下
*/

int T;
double a[N];
int n;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    double res = 0;
    for (int cnt = 1; cnt <= n; cnt++) {
        double ans = 0;
        for (int i = 1; i <= cnt; i++) {
            double c = a[i];
            for (int j = 1; j <= cnt; j++) {
                if (j != i) {
                    c *= (1 - a[j]);
                }
            }
            ans += c;
        }
        res = max(res, ans);
    }
    cout << setprecision(15) << res << "\n";
}  