/*
    https://codeforces.com/contest/924/submission/253430585
    1、j = i + 1(反证)
    2、k尽可能大（证：a/b < (a+1)/(b+1)）
    3、枚举i，二分k 或者 i和k用双指针
*/
int U, n, t;
int E[N];
void sol()
{
    cin >> n >> U;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> E[i];
        if (i >= 3 && E[i] - E[i - 2] <= U) {
            flag = true;
        }
    }
    if (!flag) {
        cout << -1 << '\n';
        return ;
    }
    double res = -1;
    for (int i = 1; i < n - 1; i++) {
        int l = i, r = n, up = E[i] + U;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (E[mid] <= up) l = mid;
            else r = mid - 1;
        }
        if (r >= i + 2) {
            res = max(res, 1.0 * (E[r] - E[i + 1]) / (E[r] - E[i]));
        }
    }
    cout << setprecision(numeric_limits<double>::max_digits10) <<  res << '\n';
}
