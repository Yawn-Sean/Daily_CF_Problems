/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-16 19:07 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int n, k;
int ans[N];

int main() {
    cin >> n >> k;
    int a = ((2ll * n) / k + 1ll - k) / 2ll;
    int cnt = 0;
    for (int i = 1; i <= k; i ++) {
        ans[i] = (i - 1ll) + a;
        cnt += max(ans[i - 1] * 2 - ans[i], 0); 
    }
    n -= (a + a + k - 1) * k / 2;
    if ((cnt < n || a <= 0)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = k; i > 1; i --) {
            if (n == 0) break; 
            if (ans[i - 1] * 2 - ans[i] >= n) {
                ans[i] += n;
                n = 0;
            } else {
                n -= ans[i - 1] * 2 - ans[i];
                ans[i] = ans[i - 1] * 2;
            }
        }
        for (int i = 1; i <= k; i ++) {
            cout << ans[i] << " \n"[i == k];
        }
    }
    return 0;
}

/*

*/
