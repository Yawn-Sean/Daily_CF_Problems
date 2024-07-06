/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-06 09:05 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int n, k;
int a[N];
int ans;
LL s[N];
int ans2;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    } 
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) {
        s[i] = a[i] + s[i - 1];
        int l = 1, r = i;
        while (l < r) {
            int mid = l + r >> 1;
            if (1ll * (i - mid + 1ll) * a[i] - s[i] + s[mid - 1] <= k) r = mid;
            else l = mid + 1;
        }
        if (ans < i - r + 1) ans2 = a[i];
        ans = max(ans, i - r + 1);
    }
    cout << ans << ' ' << ans2 << endl;
    return 0;
}

/*

*/
