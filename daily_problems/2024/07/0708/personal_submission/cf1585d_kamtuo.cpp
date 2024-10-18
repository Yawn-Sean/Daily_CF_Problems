/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-08 17:18 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 512345;

int a[N], n;
int cnt[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i)) a[i] += 1;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += a[i];
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        LL ans = 0;
        bool ok = false;
        for (int i = 1; i <= n; i ++) cnt[i] = a[i] = 0;
        for (int i = 1; i <= n; i ++) {
            int u;
            cin >> u;
            ans += query(n) - query(u);
            add(u);
            cnt[u] ++;
            if (cnt[u] >= 2) ok = true;
        }
        // cout << ans << endl;
        if (ans % 2 == 0) cout << "YES" << endl;
        else if (ans % 2 != 0 && ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/*

*/
