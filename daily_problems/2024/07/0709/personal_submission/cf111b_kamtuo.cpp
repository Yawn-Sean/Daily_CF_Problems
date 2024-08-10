/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-09 18:29 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456;

int pos[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int j = 1; j <= x / j; j ++) {
            if (x % j == 0) {
                if (i - pos[j] > y) ans ++;
                if (x / j != j && i - pos[x / j] > y) ans ++;
                pos[j] = i;
                pos[x / j] = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*

*/
