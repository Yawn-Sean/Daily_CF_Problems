/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-19 22:37 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int cnt = n - 1 - k;
    int now = 1;
    int pre = 1, tot = 0;
    vector add(k + 1, cnt / k + 1);
    int to = cnt % k;
    for (int i = 1; i <= to; i ++) {
        add[i] ++;
    }
    cout << add[1] + add[2] << endl;
    for (int i = 2; i <= n; i ++) {
        cout << pre << ' ' << i << endl;
        tot ++;
        if (tot == add[now]) {
            pre = 1;
            tot = 0;
            ++ now;
        } else {
            pre = i;
        }
    }
    return 0;
}

#endif

/*

*/
