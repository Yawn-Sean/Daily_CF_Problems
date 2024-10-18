/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-30 19:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 5123;

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    vector<LL> cnt(N, 0), va(N, 0);
    vector<LL> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            cnt[llabs(a[i] - a[j])] ++;
        }
    }
    for (int i = 1; i < N; i ++) {
        for (int j = 1; j < i; j ++) {
            va[i] += cnt[j] * cnt[i - j];
        }
    }
    LL ans = 0;
    for (int i = 1; i < N; i ++) {
        LL now = cnt[i];
        LL res = 0;
        for (int j = 1; j < i; j ++) {
            res += va[j];
        }
        ans += now * res;
    }
    printf("%.12lf", 1.0 * ans /((1.0 * (n - 1) * n / 2.0) * (1.0 * (n - 1) * n / 2.0) * (1.0 * (n - 1) * n / 2.0)));
    return 0;
}

#endif

/*

*/
