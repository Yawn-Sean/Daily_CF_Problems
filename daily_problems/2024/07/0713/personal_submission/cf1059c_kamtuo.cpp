/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-13 09:53 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 1234567;

int n, t[N], cnt[N];

int main() {
    cin >> n;
    t[0] = 1;
    for (int i = 1; i <= 20; i ++) t[i] = t[i - 1] << 1, cnt[i] = n / t[i];
    int now = n;
    for (int i = 1; i <= 20; i ++) {
        for (int j = 1; j <= now - cnt[i]; j ++) {
            cout << t[i - 1] << ' ';
        }
        now = cnt[i];
        if (cnt[i] == 1 && n / t[i - 1] >= 3) {
            cout << 3 * t[i - 1] << endl;
            break;
        }
    }
    return 0;
}

/*

*/
