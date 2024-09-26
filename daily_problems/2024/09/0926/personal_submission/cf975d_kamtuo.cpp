/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-26 09:38 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector x(n, 0ll), y(n, 0ll), vx(n, 0ll), vy(n, 0ll);
    map<std::pair<int, int>, int> mp1;
    map<long long, int> mp2;
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> vx[i] >> vy[i];
        y[i] = 1ll * a * x[i] + b;
        mp1[{vx[i], vy[i]}] ++;
        mp2[1ll * a * vx[i] - vy[i]] ++;
    }
    LL ans = 0;
    for (int i = 0; i < n; i ++) {
        ans -= mp1[{vx[i], vy[i]}];
        ans += mp2[1ll * a * vx[i] - vy[i]];
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
