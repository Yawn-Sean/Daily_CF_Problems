/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-22 20:35 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 223456, MOD = 998244353;

int cnt[N], p[N];

int main() {
    int n;
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= n; i ++) p[i] = 1ll * p[i - 1] * i % MOD;
    for (int i = 1; i <= n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        cnt[u] ++, cnt[v] ++;
    }
    int ans = n;
    for (int i = 1; i <= n; i ++) {
        ans = 1ll * ans * p[cnt[i]] % MOD;
    }
    cout << ans << endl;
    return 0;
}

/*

*/
