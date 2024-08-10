/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-24 17:14 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int n;
int a[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int g = 0;
    for (int i = 1; i <= n; i ++) {
        g = gcd(a[i], g);
    }
    if (g > 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
    } else {
        cout << "YES" << endl;
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] % 2 == 0) {
                ans += cnt / 2 + (cnt % 2) * 2ll;
                cnt = 0;
            } else {
                cnt ++;
            }
        }
        ans += cnt / 2 + (cnt % 2) * 2ll;
        cout << ans << endl;
    }
    return 0;
}

/*

*/
