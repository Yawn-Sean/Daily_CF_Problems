/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-02 17:26 */
/* Software : Visual Studio Code    */
/*----------------------------------*/
const int N = 212345, MOD = 998244353;

int a[N], n, b[N];
int st[N], m;

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> m;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            st[i] = 0;
        } 
        for (int i = 1; i <= m; i ++) {
            cin >> b[i];
            st[b[i]] = i;
        }
        LL ans = 1;
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; i ++) {
            if (st[a[i]] == 0) continue;
            LL now = 2;
            if (i - 1 <= 0 || st[a[i - 1]] > st[a[i]]) now --;
            if (i + 1 > n || st[a[i + 1]] > st[a[i]]) now --;
            ans = ans * now % MOD; 
        }
        cout << ans << endl;
    }
    return 0;
}

/*

*/
