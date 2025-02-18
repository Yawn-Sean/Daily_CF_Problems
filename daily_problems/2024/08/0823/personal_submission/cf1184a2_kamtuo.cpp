/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-23 17:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    std::function<int(int, int)> gcd = [&] (int a, int b) -> int {
        if (!b) return a;
        return gcd(b, a % b);
    };
    vector now(n, 0), ok(n + 1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (n % i == 0) {
            for (int j = 0; j < i; j ++) now[j] = 0;
            for (int j = 0; j < n; j ++) {
                now[j % i] = (s[j] - '0') ^ now[j % i]; 
            }
            for (int j = 0; j < i; j ++) {
                if (now[j]) ok[i] = 0;
            }
        }
        ans += ok[gcd(n, i)];
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
